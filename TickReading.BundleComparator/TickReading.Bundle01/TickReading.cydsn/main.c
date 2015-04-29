/* ====================================================================================
 * 
 *  ELE 302
 *  Jean Juang and Emmily Kent
 *  Speed Control PSoC Implementation
 * 
 *  Contained is the the PWM motor controller/Hall Effects Sensor/PSoC interface code.
 *  PSoC receives the "ticks" from the Hall Effects Sensor. Converts ticks into speed.
 *  Outputs pulse width modulated signal to the gate of the transistor.
 *  Used PI control.
 *
 * =================================================================================== */
  
#include <device.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846 //y u no work, math.h

typedef enum { false = 0u, true = 1u } bool;

/* Constants and variables defined for Hall Effect processing*/

static const float clock_freq = 100000; // Component clock frequency - 100kHz
static const float clock_period = 1000; // Period of the PWM. Tradeoff between resolution and speed of response. Should be updating every 0.01 seconds
static const float convert = 60/(2.459*M_PI); // Conversion factor for ticks per feet 
static float speed = 0; // current speed in feet per second
static float ticks = 0; // calculated 23.3004 ticks per second for speed = 3 feet/sec
static float ticks_per_sec = 0;
static float prevticks = 0;
static uint8 overflow = 0; // overflow counter. shouldn't update

/* PID helper variables */
    static const float target = 1.5;// target speed in ft/sec
static float error = 0; // difference between desired speed and actual speed
static float var = 0; // affects current speed
static float sum = 0; // integral
static float dt = 0; // time interval. used in integral term.

/* PID constants */
static const float kp = 1200; // proportional
static const float ki = 30; // integral

static float open_loop_guess = 110; // initialize duty cycle to 11%
static uint16 duty = 110;
static uint16 number_of_ticks = 0;

/* FSM State Initializations */

// Define states
static uint16 wait_for_elevator = 0;
static uint16 move_forward = 1;
static uint16 waiting = 2;
static uint16 in_elevator = 3;
static uint16 move_backward = 4;
static uint16 turning = 5;
static uint16 follow_line = 6;

// static uint16 testing = 33;

// Set initial state
static uint16 state = 0;

// are you going into the Elevator?
static bool isGoingElevator = false;

/*================================
// End Variable Initializations
// Interrupts Begin Here
//================================*/

// triggered with each "tick" from the Hall Effect sensor.
// monitors current speed and adjusts PWM duty cycle
CY_ISR(tock)
{ 
    /* debugging LCD display strings */
    // convert values to string for higher precision when displaying speed & ticks per second
    // char speedstr[16];
    // char errorstr[16];
    // char varstr[8];
    float prev;
    
    // counts the number of ticks to determine how far the car has traveled
    number_of_ticks = number_of_ticks + 1;  
           
    // update ticks
    ticks = (float) Hall_Counter_ReadCapture();  // elapsed time in between each tick 
    
    // change in time
    dt = (ticks)/clock_freq; //
    
    ticks_per_sec = clock_freq/ticks; // ticks per second
    
    speed = ticks_per_sec/convert; // convert ticks/sec to speed. Calculations to get convert in lab notebook.
      
    prev = error; // holds value for previous error
    error = target - speed; // current error
    sum += error*dt; // running sum of error. Integration process.
    
    var = (kp * error)+ (ki * sum);
            
    // initialize the duty cycle to the open-loop guess
    if (speed == 0) {
        duty = (uint16) open_loop_guess;
        sum = 0;
    }
    // limit the PWM duty cycle to 100%
    else if (open_loop_guess + var > (clock_period - 1.0)) 
    {
        duty = (uint16) (clock_period - 1.0);
    }
    
    // limit the PWM duty cycle to 0%
    else if (open_loop_guess + var < 0.0)
    {
        duty = 0;
    }
    // Adjust the duty cycle by the amount calculated through the PI process
    else 
    {
        duty = (uint16) (open_loop_guess + var);
    }
    
    // Display the error and PI correction value
 //   LCD_Position(0,0);
//    sprintf(errorstr, "E:%+1.3f D:%1.2f", error, (float) (duty)*100/clock_period); // * 100 to convert to percentage
//    LCD_PrintString(errorstr);
//    LCD_Position(1,0);
//    sprintf(varstr, "V:%+1.1f", var);
//    LCD_PrintString(varstr);

    LCD_Position(0,6);
    LCD_PrintNumber(state);
        
   // LCD_Position(0,5);
   // LCD_PrintNumber(duty);
    
    LCD_Position(0,10);
    if(isGoingElevator) {
        LCD_PrintString("true");
    } else {
        LCD_PrintString("false");
    }

    // meh, you can read the value of the ADC while in the tick interrupt.
    // 1 tick is ~1.545 inches traveled!
    // should use the voltage value of the rangefinder instead of the ticks -- gives you a ~consistent
    // stopping point, and can start from closer or further back from the elevator
    if (number_of_ticks >= 28 && state == move_forward) {
        // stop car!
        
        uint8 control = 0; 
        uint32 wait_milliseconds = 1000;
        
        Drive_Control_Reg_Write(control);        
        
        number_of_ticks = 0;
        // wait for elevator door to close so the rangefinder in the back doesnt get confused
        // CyDelay(wait_milliseconds); // idk... breaks things... must be bad to wait in an interrupt
        
        //LCD_Position(1,0);
        //LCD_PrintString("wait over");
        
        Wait_Counter_Start();
        state = waiting;
    }
        
if (number_of_ticks >= 105 && state == move_backward) {
        // stop car because back EMF
        uint8 control = 0;
        Drive_Control_Reg_Write(control);
        
        // sleep        
        LCD_Position(1,0);
        LCD_PrintString("s");
        LCD_Position(1,1);
        LCD_PrintString("leep"); // this is ridiculous i am sorry
        
        // turn left [as far as the wheels can go]
        PWM_Steering_WriteCompare(100);
        
        // start car again
        control = 2;
        Drive_Control_Reg_Write(control);

        number_of_ticks = 0;
        state = turning;
    }
    
    if (number_of_ticks >= 31 && state == turning) {
        uint8 control = 0;
        
        PWM_Steering_WriteCompare(152);
                
        Drive_Control_Reg_Write(control);
        
        state = 5; // 5 is turning. staying in state.
    }
    
    // duty cycle is (compare value / period val) * 100. Duty cycle is defined by compare value.
    PWM_WriteCompare(duty); // for CMP (LED input) to be true, counted value needs to be less than the compare value
    
    // clear interrupt
    Hall_Counter_ReadStatusRegister();
}

// it has been 3 minutes with no input. what did you do wrong. this should not trigger.
CY_ISR(flow)
{
   overflow++;
   /*LCD_Position(0,0);
   LCD_PrintString("Overflow        "); 
   */
   // clear interrupt
    Hall_Counter_ReadStatusRegister();
}

/* variables for steering control */
// uses PD control!
static uint8 signal_low_seen = 0;
static uint16 clock_start_time = 0;
static uint16 line_start_time = 0;
static uint16 clock_end_time = 0;
static double clock_diff_time = 0;
static double steering_error = 0;
static double steering_error_sum = 0;
static double prev_steering_error = 0;
static double derivative = 0;
static uint16 steering_value = 152; // PWM width 1.52 ms to be straight

// do something once 50th line  is read
CY_ISR(fifty)
{   clock_start_time = Line_Timer_ReadCapture();
    line_start_time = Line_Timer_ReadCapture();
    //clock_end_time = Line_Timer_ReadCapture();
    clock_diff_time = clock_start_time - line_start_time;
    steering_error = clock_diff_time - 768; // 768 = time at the middle of the line 
    steering_error_sum = steering_error_sum + steering_error;
    derivative = steering_error - prev_steering_error;
    prev_steering_error = steering_error;
    
    if (clock_diff_time > 10000) {
        // do nothing
    } else {
        /*LCD_Position(1,0);
        LCD_PrintNumber(clock_diff_time);
        
        LCD_Position(1,8); */
        
        steering_value = 152 + 0.1 * steering_error; //+ 0.4 * derivative; //+ 0.00001 * steering_error_sum;
       // LCD_Position(1,0);
       // LCD_PrintNumber(clock_diff_time);
        
        // bang-bang control
        
        /*
        if(steering_error < 999 && steering_error > 0) {
            LCD_Position(1,0);
            LCD_PrintNumber(steering_error);
        }
        else {
            LCD_Position(1,0);
            LCD_PrintNumber(999);
        }
        */
        
        // if you are line follwing, pay attention to the camera input / changes needed in wheels.
        if (state == follow_line) 
        { 
        PWM_Steering_WriteCompare(steering_value);
        }
        
        if (clock_diff_time - 400 > 0) {
        //    LCD_Position(0,5);
          //  LCD_PrintString("left");
         //   PWM_Steering_WriteCompare(100);    
        }
        else if (clock_diff_time - 400 < 0) {
        //    LCD_Position(0,5);
        //    LCD_PrintString("right");
        //    PWM_Steering_WriteCompare(200);
        }
        
    }
         
    // clear interrupt
    Line_Timer_ReadStatusRegister();
    
}

// do something once 100 lines are read
// count how many lines have been read for each frame!
CY_ISR(hundred)
{
  // counter value holds lines
    float lines;
    char linestr[16];
    
    //lines = (float) Lines_Per_Frame_Counter_ReadCounter();  // lines per frame
    
    // Display the lines per frame
   // LCD_Position(0,0);
    //sprintf(linestr, "Lines/frame:%+1.3f  ", lines); // ugly
    //LCD_PrintString(linestr);
    //LCD_PrintNumber(Lines_Per_Frame_Counter_ReadCounter());
    
  // clear interrupt
     Lines_Per_Frame_Counter_ReadStatusRegister();
}

// thrown when doors are detected to be open by front rangefinder
// rangefinder comparator value is currently set at 1.0V
CY_ISR(elevator_entering)
{
    if (state == wait_for_elevator) {
        uint8 control = 2;  // enable h-bridge, move forward

        Drive_Control_Reg_Write(control);
        state = move_forward;
    }
}

// thrown once 1.1 seconds have passed when in wait stage
CY_ISR(isr_waiting) {
    if (state == waiting) {
    
        state = in_elevator;
        
        LCD_Position(0,0);
        LCD_PrintNumber(state);
        
        LCD_Position(1,0);
        LCD_PrintString("wait over");
    }
}

// thrown when doors are detected to be open by back rangefinder
CY_ISR(elevator_leaving) {
    if (state == in_elevator) {
        uint8 control = 3; //enable h-bridge, move backward

        Drive_Control_Reg_Write(control);
        state = move_backward;
    }
}


// this interrupt is thrown each time the ADC makes a conversion.
    /*============================
    // Testing code. Delete later.
    //===========================*/
/* CY_ISR(ADC_DelSig_ISR1){

    int32 result;
    float resultInVolts;    
    char resultstr[16];
    
    LCD_Position(1,14);    
    LCD_PrintString("(:");
       
    if (state == 33) {  
        
    // write value to LCD screen
        
    result = ADC_DelSig_GetResult32();  
    //LCD_PrintNumber(result);
    
    resultInVolts = ADC_DelSig_CountsTo_Volts(result);
        
    // Display the lines per frame
   
    LCD_Position(1,0);
    sprintf(resultstr, "ADC: %1.4f", resultInVolts); // ugly
    LCD_PrintString(resultstr);
       // LCD_Position(1,0);
        //LCD_PrintNumber();
      
    }
}
   
  
*/
    /*============================
    // Testing code. Delete later.
    //===========================*/
    
void main()
{
/* Place your initialization/startup code here (e.g. MyInst_Start()) */

// temp
    uint8 start_control = 0; // start by not moving    
    
    uint16 counter_print = 0;
                 
    // Enable interrupts
    CyGlobalIntEnable;
    
    // start speed control/Hall Effect components
    Hall_Counter_Start();
    Clock_Hall_Start();    
    
    // start steering control components
    Clock_Steering_Start();
    Lines_Per_Frame_Counter_Start(); // monitors how many lines have been traversed per frame
    Camera_Comp_Start(); // initializes the comparator -- is the camera receiving black or white?
    Camera_Threshold_Start(); // Voltage that decides whether signal is black or white    
    
    // start PWM components  
    PWM_Start(); 
    PWM_Steering_Start(); 
          
    // start display LCD screen  
    LCD_Start();
    LCD_Position(0,0);    
    LCD_PrintString("State:");
    
    // start interrupt service routines
    ISR_Hall_Start();
    ISR_Hall_SetVector(tock); // convert Hall sensor "ticks" to speed, control PWM output
    ISR_Overflow_Start();
    ISR_Overflow_SetVector(flow); // monitor overflow in Hall Effects sensor. Should not trigger.
    
    ISR_50_Lines_Start(); // process image data on the 50th line
    ISR_50_Lines_SetVector(fifty);
    ISR_100_Lines_Start(); // process image data on the 100th line
    ISR_100_Lines_SetVector(hundred);
    
    Line_Timer_Start(); // DONT MOVE THIS. Timer needs to start AFTER the ISR.
   
    // Elevator
    Elevator_Threshold_Start();
    Elevator_Comparator_Start();
    ISR_Elevator_Start();
    ISR_Elevator_SetVector(elevator_entering);
    
    Elevator_Comparator_1_Start();
    ISR_Elevator_2_Start();
    ISR_Elevator_2_SetVector(elevator_leaving);
    
    //Waiting
    Wait_Clock_Start();
    ISR_Wait_Start();
    ISR_Wait_SetVector(isr_waiting);    
    
    // sets the initial speed
    PWM_WriteCompare((uint16) open_loop_guess);
    
    // enables h-bridge, forward direction
    Drive_Control_Reg_Write(start_control);
    // interrupt driven. no code here.
    
    /*============================
    // Testing code. Delete later.
    //===========================*/
/*    
      
    LCD_Position(1,0);    
    LCD_PrintString("A");
    
    
    // start ADC
    ADC_DelSig_Start();
    ADC_DelSig_IRQ_Enable(); 
    ADC_DelSig_StartConvert(); 
 */      
    /*============================
    // Testing code. Delete later.
    //===========================*/
       
    for(;;)
    {             
        //counter_print++;
        
        if (counter_print == 10000) {
            //LCD_ClearDisplay();
            
            //LCD_Position(0,5);
            //LCD_PrintNumber(duty);

            
            /*LCD_Position(0,10);
            if(isGoingElevator) {
                LCD_PrintString("true");
            } else {
             LCD_PrintString("false");
            }*/
            counter_print = 0;
        }
    }
}

/* [] END OF FILE */

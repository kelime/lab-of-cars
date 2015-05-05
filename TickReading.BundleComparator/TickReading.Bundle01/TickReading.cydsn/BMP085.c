/* ========================================
* File Name: BMP085CY.c  
*
* Version: 0
*
*  Description:
*  This driver used to interface  with the Bosch BMP085 I2C Temperature / barometric pressure  Sensor
*   http://dx.com/p/bmp085-barometric-digital-pressure-sensor-module-board-for-arduino-blue-147261
*
* Datasheet:
* The datasheet are available from their website:
* http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Sensors/Pressure/BST-BMP085-DS000-06.pdf
*
*   Note: 
*  A pressure value ranges from 30000 to 110000 pascal with a resulution
*  of 1 pascal (0.01 millibar) which enables measurements from 9000m above
*  to 500m below sea level.
*
*  The temperature values range from
*  -400 to 850 representing the ambient temperature in degree celsius
*  multiplied by 10.The resolution is 0.1 celsius.
* ===========================================================================================================
*/
#include <device.h>
#include "BMP085.h"
/* The I2C Slave address*/

uint8 oss=0;                // over-sampling ratio

uint8    RawPressure[2] = {0xf4,0x34};  // F4 -reg addr  34 - get pressure     // send code to the register F4 0x34 + (oss<<6);  see. BST-BMP085-DS000-05.pdf  pg. 13
uint8 RawTemperature[2] = {0xf4,0x2e};  // F4 -reg addr  2E - get temperature  // send code 2E  to the register F4 ( measuring the temperature)
/*______________ Кcalibration coefficients _______________________*/
short AC1=408;
short AC2=-72;
short AC3=-14383;
unsigned short AC4=32741;   // These data are taken from BST-BMP085-DS000-05.pdf
unsigned short AC5=32757;   // they can be used to check the calculations
unsigned short AC6=23153;   // if you turn off the GetCoeff()  в main.c
short B1=6190;
short B2=4;
short MB=-32768;
short MC=-8711;
short MD=2868;

long X1;
long X2;
long B5;
long B6;
long temperature;
uint8 adcBuf[1]  = {0xF6};          // Address of the first register of ADC Data (always read 3 bytes:  0xF6- MSB, 0xF7- LSB, 0xF8- XLSB )   
//_________________________________

void Wait(void)
{
	//	Do nothing (yet)
}

 
/*******************************************************************************
* Function Name:  BMP085Mesuree
********************************************************************************
*
* Summary:
*   Start measurement   (measured parametr is determined by the  *Parametrs)  
*
* Parameters:  
*  *Parametrs:  a pointer to an array of bytes sent (always 2)
*
* Return: 
*  None 
*  
*******************************************************************************/
void BMP085Mesuree(uint8 *Parametrs )
{
	I2C_Pressure_MasterWriteBuf(I2C_SLAVE_ADDRESS, Parametrs, 2, I2C_Pressure_MODE_COMPLETE_XFER);  // send a command to the measurement parameter
	//while((I2C_Pressure_MasterStatus() & I2C_Pressure_MSTAT_WR_CMPLT )==0){
    //    Wait();}		//wait until Transfer is complete
    //while(!ConversionDone){
    //}                                     		// waiting for the end of the conversion
    ConversionDone=0;                                          			// Resets the flag
}
//_________________________________________________________


/*******************************************************************************
* Function Name: BMP085GetI2C_Data
********************************************************************************
*
* Summary:
*  Query data from the device (always read 3 bytes)
*
* Parameters:  
*   *Reg:  contains the address of the first of the three read registers
*    oss:  over-sampling ratio   (values = ULTRALOWPOWER, STANDARD, HIGHRES, ULTRAHIGHRES)
*         determines the accuracy of the pressure conversion  see. BST-BMP085-DS000-05.pdf
* Return: 
*   The number in the format of long, depending on the value of oss
*   for read the calibration factors set oss = 0
*
*******************************************************************************/
long BMP085GetI2C_Data(uint8 *Reg, uint8 oss)
{
	uint8 rdBuf[3]; // here to read data
    
    I2C_Pressure_MasterWriteBuf(I2C_SLAVE_ADDRESS, Reg, 1, I2C_Pressure_MODE_COMPLETE_XFER);    // Register to read
    while((I2C_Pressure_MasterStatus() & I2C_Pressure_MSTAT_WR_CMPLT )==0);                     //wait until Transfer is complete 
          
    I2C_Pressure_MasterReadBuf(I2C_SLAVE_ADDRESS, rdBuf, 3, I2C_Pressure_MODE_COMPLETE_XFER);   // read 3 bytes
    while((I2C_Pressure_MasterStatus() & I2C_Pressure_MSTAT_RD_CMPLT )==0); 

    return  ((rdBuf[0]<<16) + (rdBuf[1]<<8) + rdBuf[2])>>(8-oss);               // return the "raw" data
}//_________________________________________________________



/*******************************************************************************
* Function Name:  GetRawTemperature
********************************************************************************
*
* Summary:
*   Get the raw temperature data
*
* Parameters:  
*  None 
*
* Return: 
*  raw temperature data
*  
*******************************************************************************/
long GetRawTemperature()
{
BMP085Mesuree(RawTemperature);              // ask to measure the temperature
return BMP085GetI2C_Data(adcBuf,0);         // get ADC data
}//____________________________________________________________________________



/*******************************************************************************
* Function Name:  GetRawPressure
********************************************************************************
*
* Summary:
*   Get the raw data pressure
*
* Parameters:  
*    oss:  over-sampling ratio   (values = ULTRALOWPOWER, STANDARD, HIGHRES, ULTRAHIGHRES)
*          determines the accuracy of the pressure conversion  see. BST-BMP085-DS000-05.pdf
*
* Return: 
*  raw data pressure  
*  
*******************************************************************************/
long GetRawPressure(uint8 oss)
{
	RawPressure[1]=0x34 + (oss<<6);         // см. BST-BMP085-DS000-05.pdf  стр. 13
	BMP085Mesuree(RawPressure);
	return  BMP085GetI2C_Data(adcBuf,oss);
}//_____________________________________________________________________________


/*******************************************************************************
* Function Name:  BMP085GetCoeff
********************************************************************************
*
* Summary:
*   Gets the BMP085 calibration coefficients 
*
* Parameters:  
*   None 
*
* Return: 
*  None 
*  
*******************************************************************************/
void BMP085GetCoeff()
{
	
uint8 eeprBuf;  // Address readable register
	eeprBuf = 0xAA;		AC1 = BMP085GetI2C_Data(&eeprBuf,0);    // for read coefficients oss = 0
	eeprBuf = 0xAC;		AC2 = BMP085GetI2C_Data(&eeprBuf,0);
	eeprBuf = 0xAE;		AC3 = BMP085GetI2C_Data(&eeprBuf,0);
	eeprBuf = 0xB0;		AC4 = BMP085GetI2C_Data(&eeprBuf,0);
	eeprBuf = 0xB2;		AC5 = BMP085GetI2C_Data(&eeprBuf,0);
	eeprBuf = 0xB4;		AC6 = BMP085GetI2C_Data(&eeprBuf,0);
	eeprBuf = 0xB6;		 B1 = BMP085GetI2C_Data(&eeprBuf,0);
	eeprBuf = 0xB8;		 B2 = BMP085GetI2C_Data(&eeprBuf,0);
	eeprBuf = 0xBA;		 MB = BMP085GetI2C_Data(&eeprBuf,0);
	eeprBuf = 0xBC;		 MC = BMP085GetI2C_Data(&eeprBuf,0);
	eeprBuf = 0xBE;		 MD = BMP085GetI2C_Data(&eeprBuf,0);
}//_________________________________________________________



/*******************************************************************************
* Function Name:  BMP085GetResult
********************************************************************************
*
* Summary:
*   Calculating the pressure in pascals and temperature in degrees Celsius
*
* Parameters:  
*   temperature - temperature in tenths of degrees
*   pressure    - pressure in Pascals
* Return: 
*  None 
*  
*******************************************************************************/
void BMP085GetResult(int* temperature, long* pressure, uint8 OSS)
{

int  RawTemp = (int) GetRawTemperature();    // get the raw temperature data

long up = GetRawPressure(OSS);          // get the raw data of pressure  (OSS - accuracy)
long x1, x2, x3, b3, b5, b6, p, tmp;    // calibration coefficients
unsigned long b4, b7;

//RawTemp = 27898;
CyDelay(1);

//расчет температуры
   x1 = ((long)RawTemp - AC6) * AC5 >> 15;
   x2 = ((long) MC << 11) / (x1 + MD);
   b5 = x1 + x2;
  *temperature = (b5 + 8) >> 4; 
  
   //расчет давления
   b6 = b5 - 4000;
   x1 = (B2 * (b6 * b6 >> 12)) >> 11; 
   x2 = AC2 * b6 >> 11;
   x3 = x1 + x2;
   //b3 = (((long) AC1) * 4 + x3)>> 2;  //bad?     http://ardupilotmega-jeti.googlecode.com/svn-history/r79/trunk/libraries/BMP085/BMP085.cpp
   //b3 = ((int32_t) AC1 * 4 + x3 + 2) >> 2;  //OK for oss=0
//***************************
   tmp=AC1;
   tmp = (tmp*4 + x3)<<OSS;
   b3 = (tmp+2)/4;
//****************************
   x1 = AC3 * b6 >> 13;
   x2 = (B1 * (b6 * b6 >> 12)) >> 16;
   x3 = ((x1 + x2) + 2) >> 2;
   b4 = (AC4 * (unsigned long) (x3 + 32768)) >> 15;
   b7 = ((unsigned long) up - b3) * (50000 >> OSS);
   p = b7 < 0x80000000 ? (b7 * 2) / b4 : (b7 / b4) * 2;
    
   x1 = (p >> 8) * (p >> 8);
   x1 = (x1 * 3038) >> 16;
   x2 = (-7357 * p) >> 16;
   *pressure = p + ((x1 + x2 + 3791) >> 4); }

//[] END OF FILE

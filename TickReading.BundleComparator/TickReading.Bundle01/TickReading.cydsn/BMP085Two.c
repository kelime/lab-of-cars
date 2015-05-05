/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <device.h>
#include "BMP085Two.h"

uint8 oss = ULTRALOWPOWER;                // over-sampling ratio

// should be 0x34?? datasheet says 0x34 + (oss<<6)
uint8 getPressure[2] = {0xF4,0xF4};  // F4 -reg addr  34 - get pressure     // send code to the register F4 0x34 + (oss<<6);  see. BST-BMP085-DS000-05.pdf  pg. 13
uint8 getTemp[2] = {0xF4,0x2E};  // F4 -reg addr  2E - get temperature  // send code 2E  to the register F4 ( measuring the temperature)

// Dummy Calibration Constants. Use to test output before reading
// the registers of the BMP085

short ac1 = 408;
short ac2 = -72;
short ac3 = -14383;
unsigned short ac4 = 32741;   // These data are taken from BST-BMP085-DS000-05.pdf
unsigned short ac5 = 32757;   // they can be used to check the calculations
unsigned short ac6 = 23153;   // if you turn off the GetCoeff()  в main.c
short b1 = 6190;
short b2 = 4;
short mb = -32768;
short mc = -8711;
short md = 2868;

long x1;
long x2;
long b5;
long b6;

uint8 ut = 0;
uint8 up = 0;
uint8 up1 = 0;
uint8 up2 = 0;
uint8 up3 = 0;

long temperature;
long pressure;

/*========================================
// Function Definitions
//=====================================*/

int getParams(void)
{
    // read all calibration data. yay. 
    ac1 = 408;
    ac2 = -72;
    ac3 = -14383;
    ac4 = 32741;   // These data are taken from BST-BMP085-DS000-05.pdf
    ac5 = 32757;   // they can be used to check the calculations
    ac6 = 23153;   // if you turn off the GetCoeff()  в main.c
    b1 = 6190;
    b2 = 4;
    mb = -32768;
    mc = -8711;
    md = 2868;

    return 1;
}

// debug -- print the temperature value read
long readTemperature()
{
    //mInterface.i2cWrite((byte) 0x77, (byte) 0xF4, (byte) 0x2E);
    I2C_Pressure_MasterWriteBuf(I2C_SLAVE_ADDRESS, getTemp, 2, I2C_Pressure_MODE_COMPLETE_XFER);
	//SystemClock.sleep(5);
    CyDelay(5);
	//ut = mInterface.i2cRead16((byte) 0x77, (byte) 0xF6);
    // without calibration data, ut should be 27898
    I2C_Pressure_MasterWriteBuf(I2C_SLAVE_ADDRESS, 0xF6, 1, I2C_Pressure_MODE_COMPLETE_XFER);
	I2C_Pressure_MasterReadBuf(I2C_SLAVE_ADDRESS, &ut, 1, I2C_Pressure_MODE_COMPLETE_XFER);
    		
    // x1 is a long -- cast ut and calibration?     
	x1 = ((long) ut - (long)ac6) * (long) ac5 / 32768;
	x2 = ((long) mc * 2048) / (x1 + (long) md);
	b5 = x1 + x2;
	temperature = (b5 + 8) / 16;
    // temp will read 150 with this calibration data
	return temperature;

}

long readPressure(oss)
{
    long x3; 
    long b3;
    long b4;
    long b7;
    
	//mInterface.i2cWrite((byte) 0x77, (byte) 0xF4, (byte) 0xF4);
    I2C_Pressure_MasterWriteBuf(I2C_SLAVE_ADDRESS, getPressure, 2, I2C_Pressure_MODE_COMPLETE_XFER);
	//SystemClock.sleep(26);
    CyDelay(26);
            
	/*up1 = mInterface.i2cRead((byte) 0x77, (byte) 0xF6);
	up2 = mInterface.i2cRead((byte) 0x77, (byte) 0xF7);
	up3 = mInterface.i2cRead((byte) 0x77, (byte) 0xF8); */
    
    up1 = I2C_Pressure_MasterReadBuf(I2C_SLAVE_ADDRESS, 0xF6, 1, I2C_Pressure_MODE_COMPLETE_XFER);
    up2 = I2C_Pressure_MasterReadBuf(I2C_SLAVE_ADDRESS, 0xF7, 1, I2C_Pressure_MODE_COMPLETE_XFER);
    up3 = I2C_Pressure_MasterReadBuf(I2C_SLAVE_ADDRESS, 0xF8, 1, I2C_Pressure_MODE_COMPLETE_XFER);
		
	up = ((up1 << 16) + (up2 << 8) + up3) >> (8 - oss);
		
	b6 = b5 - 4000;
	x1 = (b2 * (b6 * b6 / 4096)) / 2048;
	x2 = ac2 * b6 / 2048;
	x3 = x1 + x2;
	b3 = (((ac1 * 4 + x3) << oss) + 2) / 4;
	x1 = ac3 * b6 / 8192;
	x2 = (b1 * (b6 * b6 / 4096)) / 65536;
	x3 = (x1 + x2 + 2) / 4;
	b4 = ac4 * (uint32)(x3 + 32768) / 32768;
	b7 = ((uint32)up - b3) * (50000 >> oss);
	if (b7 < 0x80000000) {
		pressure = (b7 * 2) / b4;
	} else {
		pressure = (b7 / b4) * 2;
	}
	x1 = (pressure / 256) * (pressure / 256);
	x1 = (x1 * 3038) / 65536;
	x2 = (-7357 * pressure) / 65536;
	pressure = pressure + (x1 + x2 + 3791) / 16;
	return pressure;
    // dummy params should yield 69965
}
    
// sign extension for 16 bits
int signExtend16(int a)
{
    if (0 != (a&0x8000))
    { return a |= 0xffff0000;}
    
    return a;
}

// sign extension for 8 bits
int signExtend8(int a)
{
    if (0 != (a&0x80))
    {
        return a |= 0xffffff00;
    }
    
    return a;
 }


/* [] END OF FILE */

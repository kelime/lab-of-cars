/* ========================================
* File Name: BMP085Two.h  
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
#ifndef __BMP085TWO_H
#define __BMP085TWO_H
	
#include <device.h>
#include "I2C_Pressure.h"

/* The I2C Slave address*/
#define I2C_SLAVE_ADDRESS	(0x77)
#define ULTRALOWPOWER    0  // over-sampling ratio values
#define STANDARD         1
#define HIGHRES          2
#define ULTRAHIGHRES     3

// read the calibration data!
int getParams(void);

// read temperature from the chip
long readTemperature(void);

// read pressure from the chip
long readPressure(uint8 oss);

// sign extension for 16 bits
int signExtend16(int a);

// sign extension for 8 bits
int signExtend8(int a);

//[] END OF FILE

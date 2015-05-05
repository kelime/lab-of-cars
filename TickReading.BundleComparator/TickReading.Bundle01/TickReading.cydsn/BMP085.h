/* ========================================
* File Name: BMP085.h  
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
#ifndef __BMP085CY_H
#define __BMP085CY_H
	
#include <device.h>
#include "MyISRs.h"
#include "I2C_Pressure.h"

/* The I2C Slave address*/
#define I2C_SLAVE_ADDRESS	(0x77)
#define ULTRALOWPOWER    0  // over-sampling ratio values
#define STANDARD         1
#define HIGHRES          2
#define ULTRAHIGHRES     3

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
void BMP085Mesuree(uint8 *Parametrs );


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
long BMP085GetI2C_Data(uint8 *Reg, uint8 oss);



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
long GetRawTemperature();



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
long GetRawPressure(uint8 oss);


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
void BMP085GetCoeff();

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
void BMP085GetResult(int* temperature, long* pressure, uint8 OSS);

#endif

//[] END OF FILE

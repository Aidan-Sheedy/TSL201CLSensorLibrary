/**
 *******************************************************************************
 * @file	TSL201CL.h
 * @author	Aidan Sheedy
 * @version	1.0
 * @date	17-Oct-2020
 * @brief	TSL201CL Arduino Header File. This file contains all necessary
 * 			functions required to interface an Arduino with the TSL201CL chip.
 *
 * 			This file contains:
 * 				- SunSensor Class, which has three functions:
 * 					- SunSensor(int, int, int): constructor. Sets pin values 
 *					- initialize(): initializes pins
 * 					- clearRegister(): clears sensor register to get fresh
 * 					  				   readings
 * 					- readPixels(): reads analog pixel voltages and returns the
 * 					  				ADC values.
 *******************************************************************************
 */

#pragma once

#ifndef TSL201CLSENSORLIBRARY_TSL201CL_H
#define TSL201CLSENSORLIBRARY_TSL201CL_H

/**
 * Contains three functions:
 */
class SunSensor {
public:
	SunSensor(int CLK = 12, int SI = 13, int analogOut = 14);
	void initialize();
	void clearRegister() const;
	void readPixels(float *buf, int bufSize) const; // accepts array of size 64

private:
	int CLK;    // clock pin
	int SI;     // serial input pin (serial in as in serial into the sensor)
	int analogIn;   // analog input pin
};


#endif //TSL201CLSENSORLIBRARY_TSL201CL_H

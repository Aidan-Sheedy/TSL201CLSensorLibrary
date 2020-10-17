//
// Created by Aidan on 2020-10-17.
//

#include "TSL201CL.h"
#include "Arduino.h"

SunSensor::SunSensor(int CLK, int SI, int analogIn) {
	this->CLK = CLK;
	this->SI = SI;
	this->analogIn = analogIn;
}

void SunSensor::initialize() {
	pinMode(CLK, OUTPUT);
	pinMode(SI, OUTPUT);
	pinMode(analogIn, INPUT);
}

void SunSensor::clearRegister() const {
	digitalWrite(SI, HIGH); // tells TSL201 to begin pixel output cycle
	digitalWrite(CLK, HIGH);
	digitalWrite(SI, LOW);
	digitalWrite(CLK, LOW);
	for (int i = 0; i < 64; i++) { // read each pixel to reset it to 0
		digitalWrite(CLK, HIGH);
		digitalWrite(CLK, LOW);
	} // end for
}

void SunSensor::readPixels(float *buf, int bufSize) const {
  //if bufSize != 64
    //do something
	digitalWrite(SI, HIGH); // tells TSL201 to begin pixel output cycle
	digitalWrite(CLK, HIGH);
	digitalWrite(SI, LOW);
	digitalWrite(CLK, LOW);
	for (int i = 0; i < 64; i++) { // read each pixel to reset it to 0
		buf[i] = analogRead(analogIn);
		digitalWrite(CLK, HIGH);
		digitalWrite(CLK, LOW);
	} // end for
}

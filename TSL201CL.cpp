//
// Created by Aidan on 2020-10-17.
//

#include "TSL201CL.h"

void SunSensor::initialize(int CLK, int SI, int analogIn) {
	this->CLK = CLK;
	this->SI = SI;
	this->analogIn = analogIn;
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

float[64] SunSensor::readPixels() const {
	float pixels[64];
	digitalWrite(SI, HIGH); // tells TSL201 to begin pixel output cycle
	digitalWrite(CLK, HIGH);
	digitalWrite(SI, LOW);
	digitalWrite(CLK, LOW);
	for (int i = 0; i < 64; i++) { // read each pixel to reset it to 0
		pixels[i] = analogRead(analogIn);
		digitalWrite(CLK, HIGH);
		digitalWrite(CLK, LOW);
	} // end for
	return pixels;
}

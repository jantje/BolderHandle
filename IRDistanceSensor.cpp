/*
 * IRDistanceSensor.cpp
 *
 *  Created on: 28 sep. 2022
 *      Author: jan
 */

#include "IRDistanceSensor.h"

int convertAnalogToMM(int analogInput)
	{
		//TOFIX: I am assuming a lineair correlation and that is wrong
		return map(analogInput, 64, 650, 800, 100);

	}

IRDistanceSensor::IRDistanceSensor(uint8_t readPin, uint16_t readDelay, uint16_t zeroPosition)
	{
		myPin = readPin;
		myReadDelay = readDelay;
		myZeroPosition = zeroPosition;
		mydistance = ERROR_DISTANCE;
	}

void IRDistanceSensor::setup()
	{
		pinMode(myPin, INPUT);
		analogRead(myPin);
		delay(10);
		mydistance = convertAnalogToMM(analogRead(myPin));
		Serial.print("Distance initialize ");
		Serial.println(mydistance);
		for (int x = 0; x < 10; x++)
			{
				mydistanceReads.addValue(mydistance);
			}
	}

void IRDistanceSensor::loop()
	{
		static uint32_t lastDistancesSensorRead = 0;
		if ((loopMillis - lastDistancesSensorRead) > myReadDelay)
			{
				lastDistancesSensorRead = loopMillis;
				mydistanceReads.addValue(convertAnalogToMM(analogRead(myPin)));
				mydistance = mydistanceReads.getMedian();
			}
	}

/*
 * IRDistanceSensor.cpp
 *
 *  Created on: 28 sep. 2022
 *      Author: jan
 */

#include "DistanceSensorIR.h"

int convertAnalogToMM(int analogInput)
	{
		//TOFIX: I am assuming a lineair correlation and that is wrong

return analogInput;

//		return map(analogInput, 64, 650, 800, 100);

	}

DistanceSensorIR::DistanceSensorIR(uint8_t readPin, uint16_t readDelay, uint16_t zeroPosition)
	{
		myPin = readPin;
		myReadDelay = readDelay;
		myZeroPosition = zeroPosition;
		mydistance = ERROR_DISTANCE;
	}

void DistanceSensorIR::setup()
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

void DistanceSensorIR::loop()
	{
		static uint32_t lastDistancesSensorRead = 0;
		if ((loopMillis - lastDistancesSensorRead) > myReadDelay)
			{
				lastDistancesSensorRead = loopMillis;
				int analogValue=analogRead(myPin);
				int convertedValue=convertAnalogToMM(analogValue);
				mydistanceReads.addValue(convertedValue);
				mydistance = mydistanceReads.getMedian();
//				Serial.print ("IR sensor loop analog value ");
//				Serial.print (analogValue);
//				Serial.print (" MM value ");
//				Serial.print (convertedValue);
//				Serial.print (" median ");
//				Serial.println (mydistance);
			}
	}

/*
 * DistanceSensorVL53L0X.cpp
 *
 *  Created on: 7 nov. 2022
 *      Author: Jantje
 */

#include "DistanceSensorVL53L0X.h"
#include <Wire.h>

DistanceSensorVL53L0X::DistanceSensorVL53L0X(boolean startWire,
		int16_t zeroPosition) {
	myStartWire = startWire;
	myZeroPosition = zeroPosition;
	myLastRead = 0;
}

void DistanceSensorVL53L0X::loop() {
	if (loopMillis - myLastRead > 30) {
		myDistance = mySensor.readRangeContinuousMillimeters() - myZeroPosition;
		if (mySensor.timeoutOccurred()) {
			Serial.println("VL53L0X TIMEOUT");
		}
	}
}

void DistanceSensorVL53L0X::setup() {
	if (myStartWire) {
		Wire.begin();
	}
	mySensor.setTimeout(500);
	if (!mySensor.init()) {
		Serial.println("Failed to detect and initialize sensor!");
	}
	mySensor.startContinuous(30);
}


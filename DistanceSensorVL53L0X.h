/*
 * DistanceSensorVL53L0X.h
 *
 *  Created on: 7 nov. 2022
 *      Author: gast1
 */
#include "DistanceSensorInterface.h"
#include "VL53L0X.h"
#pragma once
extern uint32_t loopMillis;

class DistanceSensorVL53L0X :public DistanceSensorInterface {
public:
	DistanceSensorVL53L0X(boolean startWire,int16_t zeroPosition);
	virtual ~DistanceSensorVL53L0X(){};
	virtual int16_t getDistance(){return myDistance;};
	virtual void loop();
	virtual void setZeroPosition(int16_t zeroPosition){myZeroPosition=zeroPosition;};
	virtual void setup();
private:
	boolean myStartWire=true;
	int16_t myZeroPosition=0;
	int16_t myDistance=0;
	VL53L0X mySensor;
	uint32_t myLastRead;
};



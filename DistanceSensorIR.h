/*
 * IRDistanceSensor.h
 *
 *  Created on: 28 sep. 2022
 *      Author: jan
 */

#pragma once
#include "Arduino.h"
#include "DistanceSensorInterface.h"
#include "FastRunningMedian.h"

class DistanceSensorIR  : public DistanceSensorInterface
	{
  public:
		DistanceSensorIR(uint8_t readPin,uint16_t readDelay,uint16_t zeroPosition);
		~DistanceSensorIR(){};
       void setup();
       void loop();
       //return the distance in mm the sensor sees an object
       int16_t getDistance(){return mydistance-myZeroPosition;};
       /**
        * Set the point that is considered the 0 point
        * Assume zeroposition is set to 0 and you get a distance of 155 mm
        * If you set the zero position on 155 without moving the sensor/sensored object
        * you will get a distance of 0mm instead of 155mm
        */
       void setZeroPosition(int16_t zeroPosition){myZeroPosition=zeroPosition;};
  private:
       int myZeroPosition=0;
       FastRunningMedian<int, 10, 0> mydistanceReads;
       int16_t mydistance;
		uint8_t myPin;
		uint16_t myReadDelay;
	};

extern uint32_t loopMillis;
#define ERROR_DISTANCE -2000  //distance returned in case of error

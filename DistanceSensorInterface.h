/*
 * IDistanceSensor.h
 *
 *  Created on: 6 nov. 2022
 *      Author: gast1
 */
#pragma once
#include "Arduino.h"

class DistanceSensorInterface {
public:
	virtual  void setup();
	virtual void loop();
   //return the distance in mm the sensor sees an object
	virtual int16_t getDistance();
   /**
    * Set the point that is considered the 0 point
    * Assume zeroposition is set to 0 and you get a distance of 155 mm
    * If you set the zero position on 155 without moving the sensor/sensored object
    * you will get a distance of 0mm instead of 155mm
    */
	virtual void setZeroPosition(int16_t zeroPosition);
	virtual ~DistanceSensorInterface(){};
};



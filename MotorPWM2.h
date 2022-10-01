#pragma once
/**
 * This library controls a motor based on PWM signal.
 * This can be a continuous rotation servo or a brushless motor run by a motor driver controlled by PWM
 *
 *  * This class is specifically written to use a bycicle controller as the motor driver
 * The bycicle controller is supposed to have a voltage input that can be provided by pwm (a rc filter may be required)
 * and a direction pin that changes the direction based on a pulse on a pin
 * and a break that is on/off
 */

#include "Arduino.h"
extern uint32_t loopMillis;
#define SIGN(v)  (( (v) > 0) - ((v) < 0))


/**
 * Use this class to control a motor that needs PWM as input for speed.
 * And a pulsed pin to control direction
 *

 */
class MotorPWM2
	{
	private:
		uint8_t myPWMPin;					//The pin the motor driver speed input is attached to.
		uint8_t myBreakPin;				//The pin the motor driver's break input is attached to.
		uint8_t myDirectionPin;  //the pin for reversed direction. Use 255 when you do not have a direction pin
		boolean myReversed; //true if the motor runs in reverse

		int16_t myRequestedSpeed;
		int16_t myActualSpeed;
		uint32_t myLastSpeedChangeTime;
	public:

		MotorPWM2(uint8_t PWMPin, uint8_t breakPin, uint8_t directionPin);

		void setup();
		void loop();

		/**
		 * The last time the speed has changed.
		 */
		uint64_t getLastSpeedChangeTime()
			{
				return myLastSpeedChangeTime;
			}

		/*
		 * SetSpeed changes the speed of the motor.
		 */
		void setRequestedSpeed(int16_t Speed)
			{
				myRequestedSpeed = Speed;
			}

		int16_t getRequestedSpeed() const
			{
				return myRequestedSpeed;
			}

	};


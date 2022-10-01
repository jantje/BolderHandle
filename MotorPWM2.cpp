//#include "MaaiRobot.h"
#include "MotorPWM2.h"


#define defaultDelay 10
#define STEP 10
/**
 * The Loop method must be called directly or indirectly as part of your main Loop
 *  This does the major bulk of the work.
 *  The other  methods are getters and setters.
 */
void MotorPWM2::loop()
{
	if (myActualSpeed != myRequestedSpeed)
	{
		if (loopMillis - myLastSpeedChangeTime > defaultDelay)
		{
			myLastSpeedChangeTime = loopMillis;
			int16_t newActualSpeed = myActualSpeed;
			if (myActualSpeed < myRequestedSpeed)
			{
				newActualSpeed = min(newActualSpeed + STEP, myRequestedSpeed);
			} else
			{
				newActualSpeed = max(newActualSpeed - STEP, myRequestedSpeed);
			}

			//If we pass the stopping point wait a little longer
			if ((SIGN(newActualSpeed ) * SIGN(myActualSpeed )) < 0)
			{
				newActualSpeed = 0;
				if ((myDirectionPin < 255) )
				{
						//TOFIX this motor turning thing won't work yet
					digitalWrite(myDirectionPin, HIGH);
					delay(10);
					digitalWrite(myDirectionPin, LOW);
				}
			}

			myActualSpeed = newActualSpeed;
			analogWrite(myPWMPin,  abs(myActualSpeed));

		}
	}
}

MotorPWM2::MotorPWM2(uint8_t PWMPin, uint8_t breakPin, uint8_t directionPin)
{
	myRequestedSpeed = 0;
	myActualSpeed = 0;
	myPWMPin = PWMPin;
	myBreakPin=breakPin;
	myDirectionPin = directionPin;
	myReversed = false;
	myLastSpeedChangeTime=0;
}


/**
 * To be called as part of the setup of your sketch
 */
void MotorPWM2::setup()
{
	pinMode(myPWMPin, OUTPUT);
	pinMode(myBreakPin, OUTPUT);
	analogWrite(myPWMPin, 0);
	if (myDirectionPin < 255)
	{
		pinMode(myDirectionPin, OUTPUT);
	}
}


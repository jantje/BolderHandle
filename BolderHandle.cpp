#include "BolderHandle.h"

// pin info
#define distanceSensorPin  A0
#define ActiveSwitchPin  2
#define MOTORIGHTSPEEDPIN  3
#define MOTORLEFTSPEEDPIN  4
#define MOTORRIGHTDIRECTIONPIN  5
#define MOTORLEFTDIRECTIONPIN  6
#define LEDPin  11

//configuration stuff
#define DISTANCE_SENSOR_READ_TIME 100  //delay between the reads of the distance sensor
#define MIN_DISTANCE_CHANGE 0 //distance mm changes smaller than this are ignored
#define HANDLE_CENTRAL_POSITION 0 //assumed distance sensor says 400 mm is central position handle

int distance;

uint8_t rightMotorSpeed = 0;
uint8_t leftMotorSpeed = 0;
uint8_t rightMotorDirection = 0;  //0=forward 1=backwards
uint8_t leftMotorDirection = 0;  //0=forward 1=backwards
boolean rightMotorBreak = false;
boolean leftMotorBreakn = false;
uint32_t loopMillis;
BlinkLed myBlinkLed(LEDPin, 1000, 2000);
IRDistanceSensor myDistanceSensor(distanceSensorPin, DISTANCE_SENSOR_READ_TIME, HANDLE_CENTRAL_POSITION);
//SimpleSwitch activeSwitch(ActiveSwitchPin, HIGH);

void setup()
	{
		// Start the Serial connection
		Serial.begin(9600);
		Serial.println("BolderHandle starting up");
		pinMode(MOTORIGHTSPEEDPIN, OUTPUT);
		pinMode(MOTORLEFTSPEEDPIN, OUTPUT);
		pinMode(MOTORRIGHTDIRECTIONPIN, OUTPUT);
		pinMode(MOTORLEFTDIRECTIONPIN, OUTPUT);
		myBlinkLed.setup();
		myDistanceSensor.setup();
//		activeSwitch.setup();

		Serial.println("BolderHandle started");
		loopMillis = millis();

	}

void loop()
	{
//		static bool isActiveSwitchClosed = activeSwitch.isClosed();
		loopMillis = millis();
		//Set blink led frequency
		myBlinkLed.setOffInterval(map(distance, -40, 40, 0, 255));
//		myBlinkLed.setOnInterval(isActiveSwitchClosed ? 100 : 1000);

		myBlinkLed.loop();
		myDistanceSensor.loop();
	//	activeSwitch.loop();

		if (abs(distance - myDistanceSensor.getDistance())>MIN_DISTANCE_CHANGE)
			{
				distance = myDistanceSensor.getDistance();
				Serial.print(loopMillis);
				Serial.print(" Distance changed ");
				Serial.println(distance);

			}

//		if (isActiveSwitchClosed != activeSwitch.isClosed())
//			{
//				isActiveSwitchClosed = activeSwitch.isClosed();
//				Serial.print(loopMillis);
//				Serial.print(" Active switch toggled to ");
//				Serial.println(isActiveSwitchClosed);
//				if (isActiveSwitchClosed)
//					{
//						//TOFIX for now assuming only forward
//					} else
//					{
//
//					}
//			}

	}

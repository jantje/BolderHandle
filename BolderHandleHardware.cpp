#include "BolderHandle.h"
#include "DistanceSensorIR.h"
// pin info
#define distanceSensorPin  A0


#define LEDPin  11

//configuration stuff
#define DISTANCE_SENSOR_READ_TIME 100  //delay between the reads of the distance sensor
#define MIN_DISTANCE_CHANGE 0 //distance mm changes smaller than this are ignored
#define HANDLE_CENTRAL_POSITION 0 //assumed distance sensor says 400 mm is central position handle



BlinkLed myBlinkLed(LEDPin, 1000, 2000);
DistanceSensorIR distanceSensor(distanceSensorPin, DISTANCE_SENSOR_READ_TIME, HANDLE_CENTRAL_POSITION);
DistanceSensorInterface &myDistanceSensor=distanceSensor;
//SimpleSwitch activeSwitch(ActiveSwitchPin, HIGH);

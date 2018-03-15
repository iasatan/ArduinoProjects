#ifndef physics_h
#define physics_h
/*************************************************************************
Author:   Sátán Ádám <satanadam@outlook.com>
For Arduinos
*************************************************************************/

#include<Arduino.h>

/*
@calculates the distance, using an ultrasonic distance sensor
@params: byte trigPin, the pin where the sensors "trig pin" is attached to the arduino
byte echopin, the pin where the sencors "echo pin" is attached to the arduino
@return int distance, the calculated distance
*/
extern int calculateDistance(byte trigPin, byte echoPin);

/*
@calculates the voltage
@params: the number what analogRead() returns
@return float volt, the calculated voltage
*/
extern float convertVolts(int analogRead);

#endif
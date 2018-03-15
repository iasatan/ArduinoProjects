/*************************************************************************
Author:   Sátán Ádám <satanadam@outlook.com>
For Arduinos
**************************************************************************/


#include "Arduino.h"
#include "physics.h"

/*************************************************************************
Calculates the distance, using an ultrasonic distance sensor
*************************************************************************/

int calculateDistance(byte trigPin, byte echoPin)
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	long duration;
	int distance;
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = duration*0.034 / 2;
	return distance;
}

/*************************************************************************
Calculates the voltage
*************************************************************************/
float convertVolts(int analogRead)
{
	//I don't know why, but if I use it in a single command, it don't work
	float volt;
	volt = analogRead;
	volt = volt / 1024;
	volt = volt * 5;
	return volt;
}
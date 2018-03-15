#ifndef multimeter_h
#define multimeter_h
/*************************************************************************
Author:   Sátán Ádám <satanadam@outlook.com>
For Arduinos
*************************************************************************/

#include<Arduino.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

/*
@calculates the distance, using an ultrasonic distance sensor
@params: byte trigPin, the pin where the sensors "trig pin" is attached to the arduino
byte echopin, the pin where the sencors "echo pin" is attached to the arduino
@return int distance, the calculated distance
*/
extern void calculateCapacitance(byte OUT_PIN, byte IN_PIN, LiquidCrystal_I2C lcd);

extern void calculateBatteryState(byte BATTERY_PIN, LiquidCrystal_I2C lcd);
/*
@calculates the voltage
@params: the number what analogRead() returns
@return float volt, the calculated voltage
*/
extern float convertVolts(int analogRead);

#endif
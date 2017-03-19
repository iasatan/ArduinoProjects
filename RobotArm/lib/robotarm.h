#ifndef robotarm_h
#define robotarm_h
/*************************************************************************
Author:   Sátán Ádám <satanadam@outlook.com>
For Arduinos
*************************************************************************/

#include<Arduino.h>
#include<Servo.h>

/*
@moves the servo with given speed
@params: Servo myServo, the servo you want to move
		 byte newPos, the new position where we want to move the servo
		 byte wait, delay between movements
@return: none
*/
extern void migrate(Servo myServo, byte newPos, byte wait);
/*
@moves servos with given speed
@params: Servo servo1, the servo you want to move
		 byte newPos1, the new position where we want to move the servo
		 Servo servo2, the servo you want to move
		 byte newPos2, the new position where we want to move the servo
		 byte wait, delay between movements
@return: none
*/
extern void migrate(Servo servo1, byte newPos1, Servo servo2, byte newPos2, byte wait);
/*
@moves servos with given speed
@params: Servo servo1, the servo you want to move
		 byte newPos1, the new position where we want to move the servo 
		 Servo servo2, the servo you want to move 
		 byte newPos2, the new position where we want to move the servo 
		 Servo servo3, the servo you want to move
		 byte newPos3, the new position where we want to move the servo
		 byte wait, delay between movements
@return: none
*/
extern void migrate(Servo servo1, byte newPos1, Servo servo2, byte newPos2, Servo servo3, byte newPos3, byte wait);
/*
@moves servos with given speed
@params: Servo servo1, the servo you want to move
		 byte newPos1, the new position where we want to move the servo
		 Servo servo2, the servo you want to move
		 byte newPos2, the new position where we want to move the servo
		 Servo servo3, the servo you want to move
		 byte newPos3, the new position where we want to move the servo
		 Servo servo4, the servo you want to move
		 byte newPos4, the new position where we want to move the servo
		 byte wait, delay between movements
@return: none
*/
extern void migrate(Servo servo1, byte newPos1, Servo servo2, byte newPos2, Servo servo3, byte newPos3, Servo servo4, byte newPos4, byte wait);

#endif

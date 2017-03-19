/*************************************************************************
Author:   Sátán Ádám <satanadam@outlook.com>
For Arduinos
**************************************************************************/


#include "Arduino.h"
#include "robotarm.h"
#include "Servo.h"

/*************************************************************************
 Moves a servo to "newPos"
*************************************************************************/
void migrate(Servo myServo, byte newPos, byte wait){
	byte pos=myServo.read(); //reads the current position of the servo
	if (pos < newPos){
		for (int i = pos; i < newPos; i++){
			myServo.write(i);
			delay(wait);
		}
	}
	else{
		for (int i = pos; i > newPos; i--){
			myServo.write(i);
			delay(wait);
		}
	}
}
/*************************************************************************
Moves the servos to the newPos-es
*************************************************************************/
void migrate(Servo servo1, byte newPos1, Servo servo2, byte newPos2, byte wait) {
	byte pos1 = servo1.read(); //reads the current position of the servo
	byte pos2 = servo2.read();
	while (true) {
		if (pos1 != newPos1) {
			delay(wait / 2);
			if (pos1 <= newPos1) 
				pos1++;
			
			else if (pos1 > newPos1) 
				pos1--;
			
			servo1.write(pos1);
		}
		else
			delay(wait / 2);
		if (pos2 != newPos2) {
			delay(wait / 2);
			if (pos2 <= newPos2) 
				pos2++;
			else if (pos2 > newPos2) 
				pos2--;
			servo2.write(pos2);
		}
		else 
			delay(wait / 2);
		if (pos1 == newPos1 && pos2 == newPos2)
			break;
	}
}
/*************************************************************************
Moves the servos to the newPos-es
*************************************************************************/
void migrate(Servo servo1, byte newPos1, Servo servo2, byte newPos2, Servo servo3, byte newPos3, byte wait) {
	byte pos1 = servo1.read(); //reads the current position of the servo
	byte pos2 = servo2.read();
	byte pos3 = servo3.read();
	while (true) {
		if (pos1 != newPos1) {
			delay(wait / 3);
			if (pos1 < newPos1) 
				pos1++;
			else if (pos1 > newPos1) 
				pos1--;
			servo1.write(pos1);
		}
		else 
			delay(wait / 3);
		if(pos2 != newPos2) {
			delay(wait / 3);
			if (pos2 < newPos2)
				pos2++;
			else if (pos2 > newPos2) 
				pos2--;
			servo2.write(pos2);
		}
		else 
			delay(wait / 3);
		if (pos3 != newPos3) {
			delay(wait / 3);
			if (pos3 < newPos3)
				pos3++;
			else if (pos3 > newPos3)
				pos3--;
			
			servo3.write(pos3);
		}
		else
			delay(wait / 3);
		if (pos1 == newPos1 && pos2 == newPos2 && pos3 == newPos3)
			break;
	}
}

/*************************************************************************
Moves the servos to the newPos-es
*************************************************************************/

void migrate(Servo servo1, byte newPos1, Servo servo2, byte newPos2, Servo servo3, byte newPos3, Servo servo4, byte newPos4, byte wait) {
	byte pos1 = servo1.read(); //reads the current position of the servo
	byte pos2 = servo2.read();
	byte pos3 = servo3.read();
	byte pos4 = servo4.read();
	while (true) {
		if (pos1 != newPos1) {
			delay(wait / 4);
			if (pos1 < newPos1) 
				pos1++;
			else if (pos1 > newPos1)
				pos1--;
			servo1.write(pos1);
		}
		else 
			delay(wait / 4);
		if(pos2 != newPos2) {
			delay(wait / 4);
			if (pos2 < newPos2)
				pos2++;
			else if (pos2 > newPos2)
				pos2--;
			servo2.write(pos2);
		}
		else 
			delay(wait / 4);
		if (pos3 != newPos3) {
			delay(wait / 4);
			if (pos3 < newPos3)
				pos3++;
			else if (pos3 > newPos3)
				pos3--;
			servo3.write(pos3);
		}
		else
			delay(wait / 4);
		if (pos4 != newPos4) {
			delay(wait / 4);
			if (pos4 < newPos4)
				pos4++;
			else if (pos4 > newPos4)
				pos4--;
			servo4.write(pos4);
		}
		else 
			delay(wait / 4);
		if (pos1 == newPos1 && pos2 == newPos2 && pos3 == newPos3 && pos4 == newPos4)
			break;
	}
}

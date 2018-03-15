#include <Servo.h>

#define joystickPanPin            A0
#define joystickTiltPin           A1
#define servoPanPin               9
#define servoTiltPin              10

Servo panServo;      
Servo tiltServo;  
    

int servoPanPosition = 90;
int servoTiltPosition = 90;
int joystickPanSpeed = 0;
int joystickTiltSpeed = 0;


void setup()
{
  pinMode(servoPanPin, OUTPUT);
  pinMode(servoTiltPin, OUTPUT);
  panServo.attach(servoPanPin);
  tiltServo.attach(servoTiltPin);
}


void loop()
{
  joystickPanSpeed = (analogRead(joystickPanPin) - 518) / 50;
    // -512 to provide equal +/- numbers
  joystickTiltSpeed = (analogRead(joystickTiltPin) - 511) / -50;
    // negative 50 to reverse direction

  servoPanPosition = constrain((servoPanPosition + joystickPanSpeed), 1, 180);
  servoTiltPosition = constrain((servoTiltPosition + joystickTiltSpeed), 1, 180);
    // constarin function to not exceed servo limits

  panServo.write(servoPanPosition);
  tiltServo.write(servoTiltPosition);

  delay(50);
    // adjustable for overall speed
}

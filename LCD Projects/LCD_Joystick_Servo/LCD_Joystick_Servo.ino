#include <Servo.h>
//Define variables 

//Servos
#define servoClawPin              8
#define handPin                   9
#define elbowPin                  10
#define shoulderPanPin            11
#define shoulderTiltPin           12

#define buttonPin                 5

Servo clawServo;  
Servo handServo;      
Servo elbowServo;
Servo shoulderPanServo;
Servo shoulderTiltServo;
/*
byte servoPanPosition = 90;
byte servoTiltPosition = 90;
int joystickPanSpeed = 0;
int joystickTiltSpeed = 0;
byte panPrevPos=90;
byte tiltPrevPos=90;
byte buttonState=0;
byte opened=0;
byte i;

*/

byte clawPosition;
byte handPosition;
byte elbowPosition;
byte shoulderPanPosition;
byte shoulderTiltPosition;
byte
byte
void initServos()
{
  
}
void setup()
{
  pinMode(servoClawPin, OUTPUT);
  pinMode(handPin, OUTPUT);
  pinMode(elbowPin, OUTPUT);
  pinMode(shoulderPanPin, OUTPUT);
  pinMode(shoulderTiltPin, OUTPUT);
  Serial.begin(9600);
  clawServo.attach(8);
  handServo.attach(9);
  elbowServo.attach(10);
  shoulderPanServo.attach(11);
  shoulderTiltServo.attach(12);
  
  pinMode(buttonPin, INPUT);
  elbowPosition = constrain(elbowPosition, 0, 145);
}



/*
void controllTheServosWithJoystick()
{
  joystickPanSpeed = (analogRead(joystickPanPin) - 468) / 50;  // -512 to provide equal +/- numbers
  joystickTiltSpeed = (analogRead(joystickTiltPin) - 511) / -50; // negative 50 to reverse direction

  servoPanPosition = constrain((servoPanPosition + joystickPanSpeed), 53, 180); 
  servoTiltPosition = constrain((servoTiltPosition + joystickTiltSpeed), 0, 180);
    // constarin function to not exceed servo limits
  
  
  
  if(tiltPrevPos != servoTiltPosition)
  {
    tiltServo.attach(servoTiltPin);
    tiltServo.write(servoTiltPosition); 
  }
  else
  {
    tiltServo.detach();
  }

  
  if(panPrevPos != servoPanPosition)
  {
    panServo.attach(servoPanPin);
    panServo.write(servoPanPosition);
  }
  else
  {
    panServo.detach();
  }

  
  tiltPrevPos=servoTiltPosition;
  panPrevPos=servoPanPosition;
}

void clawMover()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    if(opened==0)
    {
      opened=1;
    }
    else if(opened==1)
    {
      opened=0;
    }
    
    clawServo.attach(servoClawPin);
    if (opened==0)
    { 
      for (i=66; i < 140; i++)
      {
        clawServo.write(i);
        delay(15); 
      }
    } 
    else 
    {  
      for (i=140; i > 66; i--) 
      { 
        clawServo.write(i);
        delay(15);  
      }
    }
    delay(50);
    clawServo.detach();
  }
}
*/
void loop()
{
  Serial.println("Init ok");
  delay(100);
  clawServo.write(140);
  Serial.println("claw ok");
  delay(2000);
  handServo.write(90);
  Serial.println("handPan ok");
  delay(2000);
  elbowServo.write(70);
  Serial.println("elbow ok");
  delay(2000);
  shoulderPanServo.write(90);
  Serial.println("shoulderPan ok");
  delay(2000);
  shoulderTiltServo.write(90);
  Serial.println("shoulderTilt ok");
  delay(2000);
  //clawMover();
  //controllTheServosWithJoystick();
  delay(50);
}

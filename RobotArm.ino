#include <Servo.h>
#include<robotarm.h>

Servo clawServo;  
Servo handServo;      
Servo elbowServo;
Servo shoulderPanServo;
Servo shoulderTiltServo;

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(3, OUTPUT);
 
  
  Serial.begin(9600);
  
  clawServo.attach(8);
  handServo.attach(9);
  elbowServo.attach(10);
  shoulderPanServo.attach(11);
  shoulderTiltServo.attach(12);
  clawServo.write(140);
  handServo.write(90);
  elbowServo.write(90);
  shoulderPanServo.write(90);
  shoulderTiltServo.write(90);
  }
//void loop(){}

void loop()
{
  byte hundredByte;
  byte tenByte;
  byte oneByte;
  char serialServo;
  byte serialPos;
  if(Serial.available()>0)
  {
    serialServo=Serial.read();
    char hundredChar=Serial.read();
    char tenChar=Serial.read();
    char oneChar=Serial.read();
    hundredByte=hundredChar-'0';
    hundredByte=hundredByte*100;
    tenByte=tenChar-'0';
    tenByte=tenByte*10;
    oneByte=oneChar-'0';
    serialPos=hundredByte+tenByte+oneByte;
    Serial.println(serialPos);
  }
  if(serialServo=='c')//claw
  {
    Serial.println("Claw");
    serialPos = constrain(serialPos, 66, 140);
    migrate(clawServo,serialPos, 15);
    serialServo=' ';
  }
  else if(serialServo=='h')//hand
  {
    Serial.println("hand");
    migrate(handServo,serialPos, 25);
    serialServo=' ';
  }
  else if(serialServo=='e')//elbow
  {
    Serial.println("elbow");
    serialPos = constrain(serialPos, 0, 145);
    migrate(elbowServo,serialPos, 25);
    serialServo=' ';
  }
  else if(serialServo=='p')//shoulderPan
  {
    Serial.println("shoulderPan");
    migrate(shoulderPanServo,serialPos, 25);
    serialServo=' ';
  }
  else if(serialServo=='t')//shoulderTilt
  {
    Serial.println("shoulderTilt");
    migrate(shoulderTiltServo,serialPos,25);
    serialServo=' ';
  }
  else if(serialServo=='b')
  {
    migrate(shoulderTiltServo,serialPos,25);
    migrate(shoulderPanServo,serialPos, 25);
    migrate(elbowServo,serialPos, 25);
    migrate(handServo,serialPos, 25);
    clawServo.write(serialPos);
  }
  delay(100);
}

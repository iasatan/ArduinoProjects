#include <Servo.h>

#define Wait 15

Servo clawServo;  
Servo handServo;      
Servo elbowServo;
Servo panServo;
Servo tiltServo;

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
  Serial.begin(9600);

  initServos();
}

void initServos(){
  clawServo.attach(9);
  handServo.attach(8);
  elbowServo.attach(10);
  tiltServo.attach(11);
  panServo.attach(12);
  clawServo.write(140);
  handServo.write(180);
  elbowServo.write(90);
  panServo.write(90);
  tiltServo.write(90);
}

void shake(byte times){
  for(int i=0;i<times;i++){
      migrate(panServo, 130, 10);
      migrate(panServo, 70, 10);
      delay(100);
  }
  migrate(panServo, 100, 10);
}

void armSwing(){
  migrate(tiltServo, 180, 10);
  migrate(handServo, 90, 10);
  migrate(elbowServo, 0, 10);
  migrate(elbowServo, 10, 10);
  migrate(tiltServo, 50, 10);
}

void highFive(byte serialPos){
  shake(serialPos);
  migrate(tiltServo, 180, 10);
  migrate(handServo, 90, 10);
  migrate(elbowServo, 0, 10);
  migrate(elbowServo, 10, 10);
  migrate(tiltServo, 50, 10);
}

void wave(int times){
  elbowServo.write(20);
  for(int k=0;k<times;k++){
    migrate(handServo,70, Wait);
    Serial.println(k);
    migrate(handServo,130, Wait);
  }
}

void masturbate(byte  times){
  tiltServo.write(90);
  int z, u;
  for(int l=0; l<times;l++){
    for(z=70, u=30; z<130;z++, u++){
      handServo.write(u);
      elbowServo.write(z);
      delay(14);
    }
  }
}
void rest(){
  migrate(panServo,90,Wait);
  migrate(elbowServo,180, Wait);
  migrate(tiltServo,180, Wait);
  migrate(handServo,180, Wait);
  tiltServo.detach();
  panServo.detach();
  elbowServo.detach();
  handServo.detach();
}
  
void migrate(Servo myServo, byte newPos, byte wait)
{
  byte pos=myServo.read(); //reads the current position of the servo
  if (pos < newPos)
  {
    for (int i = pos; i < newPos; i++)
    {
      myServo.write(i);
      delay(wait);
    }
  }
  else
  {
    for (int i = pos; i > newPos; i--)
    {
      myServo.write(i);
      delay(wait);
    }
  }
}
void loop()
{
  byte hundredByte;
  byte tenByte;
  byte oneByte;
  char serialServo;
  byte serialPos;

  char hundredChar;
  char tenChar;
  char oneChar;
  
  if(Serial.available()>0) //converts the incoming data into angle and servotag
  {
    serialServo=Serial.read();
    hundredChar=Serial.read();
    tenChar=Serial.read();
    oneChar=Serial.read();
    hundredByte=hundredChar-'0';
    hundredByte=hundredByte*100;
    tenByte=tenChar-'0';
    tenByte=tenByte*10;
    oneByte=oneChar-'0';
    serialPos=hundredByte+tenByte+oneByte;
    Serial.println(serialPos);
  }

  switch (serialServo) {
      case 'c': //claw
        Serial.println("Claw");
        serialPos = constrain(serialPos, 66, 140);
        migrate(clawServo,serialPos, Wait);
        break;
      case 'h': //hand
        Serial.println("hand");
        migrate(handServo,serialPos, Wait);
        break;
      case 'e': //elbow
        Serial.println("elbow");
        serialPos = constrain(serialPos, 0, 155);
        migrate(elbowServo,serialPos, Wait);
        break;
      case 'p': //shoulderPan
        Serial.println("shoulderPan");
        migrate(panServo,serialPos, 25);
        break;
      case 't': //shoulderTilt
        Serial.println("shoulderTilt");
        migrate(tiltServo,serialPos,Wait);
        break;
      case 'r': //resting
        rest();
        break;
      case 's': //start
        initServos();
        break;
      case 'w': //wave
        wave(serialPos);
        break;
      case 'm': //masturbate
        masturbate(serialPos);
        break;
      case 'f': //highFive
        highFive(serialPos);
        break;
  }
  serialServo=' ';
  delay(100);
}

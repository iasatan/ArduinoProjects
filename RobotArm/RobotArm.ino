#include <Servo.h>
#include <robotarm.h>

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
        migrate(clawServo,serialPos, 15);
        break;
      case 'h': //hand
        Serial.println("hand");
        migrate(handServo,serialPos, 15);
        break;
      case 'e': //elbow
        Serial.println("elbow");
        serialPos = constrain(serialPos, 0, 155);
        migrate(elbowServo,serialPos, 15);
        break;
      case 'p': //shoulderPan
        Serial.println("shoulderPan");
        migrate(panServo,serialPos, 25);
        break;
      case 't': //shoulderTilt
        Serial.println("shoulderTilt");
        migrate(tiltServo,serialPos,15);
        break;
      case 'r': //resting
        Serial.println("resting");
        rest();
        break;
      case 's': //start
        Serial.println("start");
        initServos();
        break;
      case 'w': //wave
        Serial.println("wave");
        wave(serialPos);
        break;
      case 'm': //masturbate
        Serial.println("masturbate");
        masturbate(serialPos);
        break;
      case 'f': //highFive
        Serial.println("highFive");
        highFive(serialPos);
        break;
      case 'q':
        Serial.println("test");
        migrate(panServo, 0, handServo, 90, 10);
  }
  serialServo=' ';
  delay(100);
}

void rest(){
  migrate(handServo, 180, elbowServo, 180, tiltServo, 180, panServo, 90, 15);
  delay(100);
  tiltServo.detach();
  panServo.detach();
  elbowServo.detach();
  handServo.detach();
}

void masturbate(byte times){
  tiltServo.write(90);
  for (int l = 0; l<times; l++) {
    migrate(handServo, 80, elbowServo, 80, 18);
    migrate(handServo, 40, elbowServo, 130, 18);
  }
}

void wave(byte times){
  migrate(panServo, 0, elbowServo, 20, 10);
  //migrate(panServo, 0, 10);
  //elbowServo.write(20);
  for (int k = 0; k<times; k++) {
    migrate(handServo, 70, 15);
    migrate(handServo, 130, 15);
  }
}

void shake(byte times){
  migrate(handServo, 180, 10);
  for (int i = 0; i<times; i++) {
    migrate(panServo, 130, 10);
    migrate(panServo, 70, 10);
    delay(100);
  }
  migrate(panServo, 100, 10);
}

void highFive(byte times){
  shake(times);
  migrate(tiltServo, 180, 10);
  migrate(handServo, 90, 10);
  migrate(elbowServo, 0, 10);
  migrate(elbowServo, 10, 10);
  migrate(tiltServo, 50, 10);
  migrate(tiltServo, 180, 10);
  migrate(tiltServo, 50, 25);
  delay(1000);
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
  tiltServo.write(100);
}


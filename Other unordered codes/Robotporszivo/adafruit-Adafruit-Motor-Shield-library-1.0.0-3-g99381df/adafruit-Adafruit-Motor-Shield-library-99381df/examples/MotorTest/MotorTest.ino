// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motorR(1);
AF_DCMotor motorL(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motorR.setSpeed(200);
  motorL.setSpeed(200);
 
  motorR.run(RELEASE);
}

void loop() {
  uint8_t i;
  
  Serial.print("tick");
  
  motorR.run(FORWARD);
  motorL.run(FORWARD);
  for (i=100; i<255; i++) {
    motorR.setSpeed(i);  
    motorL.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=100; i--) {
    motorR.setSpeed(i);  
    motorL.setSpeed(i);
    delay(10);
 }
  
  Serial.print("tock");

  motorR.run(BACKWARD);
  motorL.run(BACKWARD);
  for (i=1000; i<255; i++) {
    motorR.setSpeed(i);
    motorL.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=100; i--) {
    motorR.setSpeed(i);  
    motorL.setSpeed(i); 
    delay(10);
 }
  

  Serial.print("tech");
  motorR.run(RELEASE);
  motorL.run(RELEASE);
  delay(1000);
}

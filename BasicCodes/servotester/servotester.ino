#include<Servo.h>

Servo servo;

//Servo servo2;
int i;

void setup() {
  //Serial.begin(9600);
  // put your setup code here, to run once:
  servo.attach(9);
  //servo2.attach(8);
  servo.write(90);
  //delay(10000);
  //servo.write(90);
  //delay(10000);
  //servo.write(180);
  //delay(10000);
  //servo.write(90);
  delay(1000);

}

void loop() {
  
   //servo.attach(8);
  // put your main code here, to run repeatedly:
  /*for(i=0;i<180;i++)
  {
    servo.write(i);
    //servo2.write(i);
    Serial.println(i);
    delay(100);
  }
  for(i=180;i>0;i--)
  {
    servo.write(i);
    Serial.println(i);
    delay(100);
  }
  //servo.write(140);
delay(2000);
*/

}


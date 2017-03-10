#include <Servo.h>

#define   vertpin  8
#define   horpin   9

Servo vert; 
Servo hor;

byte i;
byte wait;
byte pos;
short megarand;
byte rand1;
byte rand2;

void setup() 
{
  vert.attach(vertpin);
  hor.attach(horpin);  
}

void migrate(Servo &myServo, int newPos)
{
  wait=random(0,20);
  pos = myServo.read();
  if (pos < newPos)
  { 
    for (i=pos; i < newPos; i++)
    {
      myServo.write(i);
      delay(wait); 
    }
    myServo.detach();
  } 
  else 
  { 
    for (i=pos; i > newPos; i--) 
    { 
      myServo.write(i);
      delay(wait);  
    }
    myServo.detach();
  }
}
  
void loop() { 
  megarand=random(100,800);
  vert.attach(vertpin);
  hor.attach(horpin); 
  rand1=random(150, 180);
  rand2=random(0,30);
  migrate(hor, rand1);
  migrate(vert, rand2);
  delay(megarand);
}


#include<multimeter.h>
float highT = 1;

float lowT = 0.5;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  float a = convertVolts(analogRead(4));
  delay(1000);
  
  if(a>highT)
  {
    Serial.print("; Good ");
    Serial.print(a);
    Serial.print("V");

  }
  else if(a>lowT)
  {
    Serial.print("; Ok ");
    Serial.print(a);
    Serial.print("V");
  }
  else
  {
    Serial.print("; Bad ");
    Serial.print(a);
    Serial.print("V");
  }
}

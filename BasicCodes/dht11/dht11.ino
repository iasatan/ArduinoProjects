
#include <dht.h>

#define dht_dpin A0

dht DHT;
int temp=0;
int humidity=0;

void setup(){
  Serial.begin(9600);
  delay(300);//Let system settle
  Serial.println("Humidity and temperature\n\n");
  delay(700);//Wait rest of 1000ms recommended delay before
}

void loop(){
  DHT.read11(dht_dpin);
  if(DHT.temperature!=temp)
  {
    temp=DHT.temperature;
    Serial.print("temperature = ");
    Serial.print(temp); 
    Serial.println("C  ");
  }
  if(DHT.humidity!=humidity)
  {
    humidity=DHT.humidity;
    Serial.print("Current humidity = ");
    Serial.print(humidity);
    Serial.println("%  ");
  }
  delay(800);//Don't try to access too frequently... in theory
}


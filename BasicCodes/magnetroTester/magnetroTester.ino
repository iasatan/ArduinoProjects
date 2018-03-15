#define switchPin 2 // Reed switch to digital pin 2

void setup() {
pinMode(switchPin, INPUT); // switchPin is an input
digitalWrite(switchPin, HIGH); // Activate internal pullup resistor
Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(switchPin)); // Display current value
  //switch is closed (magnet is near), the value is 0 (LOW)
  //switch is open (magnet is removed), the value is 1 (HIGH)
  delay(200);
}

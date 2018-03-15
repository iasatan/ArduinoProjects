const byte MQ2Pin = A0; //LPG, i-butane, propane, methane ,alcohol, hydrogen and smoke.
int MQ2Value;

void setup() {
  pinMode(MQ2Pin, INPUT);
  Serial.begin(9600);
  delay(300);//Let system settle
}

void loop() {
  MQ2Value = analogRead(MQ2Pin);
  Serial.println(MQ2Value);
  delay(1000);
}

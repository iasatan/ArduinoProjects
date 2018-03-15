const byte MQ2Pin = A0; //LPG, i-butane, propane, methane ,alcohol, hydrogen and smoke.
const byte MQ3Pin = A1; //Alcohol, Ethanol, smoke
const byte MQ4Pin = A2; //Methane, CNG Gas
const byte MQ5Pin = A3; //Natural gas, LPG
const byte MQ6Pin = A4; //LPG, butane gas
const byte MQ7Pin = A5; //Carbon Monoxide
const byte MQ8Pin = 13; //Hydrogen Gas
const byte MQ9Pin = 12; //Carbon Monoxide, flammable gasses.
const byte MQ135Pin = 11; //Benzene, Alcohol, smoke
int MQ2Value;
int MQ3Value;
int MQ4Value;
int MQ5Value;
int MQ6Value;
int MQ7Value;
int MQ8Value;
int MQ9Value;
int MQ135Value;

void setup() {
  pinMode(MQ2Pin, INPUT);
  pinMode(MQ3Pin, INPUT);
  pinMode(MQ4Pin, INPUT);
  pinMode(MQ5Pin, INPUT);
  pinMode(MQ6Pin, INPUT);
  pinMode(MQ7Pin, INPUT);
  pinMode(MQ8Pin, INPUT);
  pinMode(MQ9Pin, INPUT);
  pinMode(MQ135Pin, INPUT);
}

void loop() {
  MQ2Value = analogRead(MQ2Pin);
  MQ3Value = analogRead(MQ3Pin);
  MQ4Value = analogRead(MQ4Pin);
  MQ5Value = analogRead(MQ5Pin);
  MQ6Value = analogRead(MQ6Pin);
  MQ7Value = analogRead(MQ7Pin);
  MQ8Value = analogRead(MQ8Pin);
  MQ9Value = analogRead(MQ9Pin);
  MQ135Value = analogRead(MQ135Pin);
  
}

#define sensorPin  A0
#define Vin        5
#define Rref       999

int sensorValue = 0;       // sensorPin default value
float Vout = 0;            // Vout default value
float R = 0;               // Tested resistors default value

void setup ()
{
  Serial.begin(9600);      // Initialize serial communications at 9600 bps
}

void loop ()
{
  sensorValue = analogRead(sensorPin);  // Read Vout on analog input pin A0 (Arduino can sense from 0-1023, 1023 is 5V)
  Vout = (Vin * sensorValue) / 1023;    // Convert Vout to volts
  R = Rref * (1 / ((Vin / Vout) - 1));  // Formula to calculate tested resistor's value
  Serial.print("R: ");                  
  Serial.println(R);                    // Give calculated resistance in Serial Monitor
  delay(1000);                          // Delay in milliseconds between reeds
}

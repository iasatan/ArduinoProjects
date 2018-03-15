#define trigPin     10
#define echoPin     11
// Variables for the duration and the distance
long duration;
int distance1, distance2;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
}
void loop() {
  distance1 = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  if(distance2!=distance1)
  {
    Serial.print(distance1); // Sends the distance value into the Serial Port
    Serial.print("cm  ");
    delay(1000);
  }
  else
  {
    Serial.print("same");
    
  }
  distance2=distance1;
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance1= duration*0.034/2;
  return distance1;
}

//Neccesery for the LCD 

//Libraries
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <multimeter.h>

//Define variables 

#define I2C_ADDR          0x27        //Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN      3
#define En_pin             2
#define Rw_pin             1
#define Rs_pin             0
#define D4_pin             4
#define D5_pin             5
#define D6_pin             6
#define D7_pin             7
#define LcdColumn          16
#define LcdRow             2
#define CapacitanceOUT_PIN A3
#define CapacitanceIN_PIN  A1
#define BATTERY_PIN        0
#define button1Pin         2
#define button2Pin         3
#define button3Pin         4
#define sensorPin          A0
#define Vin                5
#define Rref               999

//Initialise the LCD
LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
//-------------------------------------------------------------------------------------

//Digital Capacitance Meter
//Measuring from 0.000pF to 1000uF

int button1State;
int button2State;
int button3State;
int sensorValue = 0;       
float Vout = 0;            
float R = 0; 



void setup()
{
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(CapacitanceOUT_PIN, OUTPUT);
  pinMode(CapacitanceIN_PIN, OUTPUT);
  
  lcd.begin(LcdColumn, LcdRow); //Inicalizing LCD
  
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE); 
  lcd.setBacklight(HIGH);  //Sets the backlight to maximum
  }

void loop()
{
  button1State=digitalRead(button1Pin);
  button2State=digitalRead(button2Pin);
  button3State=digitalRead(button3Pin);
  if(button1State==HIGH)
  {
    calculateCapacitance(CapacitanceOUT_PIN, CapacitanceIN_PIN, lcd);
  }
  else if(button2State==HIGH)
  {
    calculateBatteryState(BATTERY_PIN, lcd);
  }
  else if(button3State==HIGH)
  {
    sensorValue = analogRead(sensorPin);  // Read Vout on analog input pin A0 (Arduino can sense from 0-1023, 1023 is 5V)
    Vout = (Vin * sensorValue) / 1023;    // Convert Vout to volts
    R = Rref * (1 / ((Vin / Vout) - 1));  // Formula to calculate tested resistor's value
    lcd.write("Resistence:");
    if(R<1000)
     {
      lcd.write(R);
      lcd.write("ohm");
     }
     else if(R>1000 && R<1000000)
     {
      lcd.write(R/1000);
      lcd.write("Kohm");
     }
     else if(R>1000000 && R<1000000000)
     {
      lcd.write(R/1000000);
      lcd.write("Mohm");
     }
  }
}

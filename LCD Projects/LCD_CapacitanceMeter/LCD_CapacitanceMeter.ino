//Neccesery for the LCD 

//Libraries
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

//Define variables 

#define I2C_ADDR             0x27        //Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN        3
#define En_pin               2
#define Rw_pin               1
#define Rs_pin               0
#define D4_pin               4
#define D5_pin               5
#define D6_pin               6
#define D7_pin               7
#define OUT_PIN              A3
#define IN_PIN               A1
#define IN_CAP_TO_GND        24.48
#define R_PULLUP             34.8  
#define MAX_ADC_VALUE        1023
#define LcdColumn            16
#define LcdRow               2

//Initialise the LCD
LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
//-------------------------------------------------------------------------------------

//Digital Capacitance Meter
//Measuring from 0.000pF to 1000uF

void setup()
{
  pinMode(OUT_PIN, OUTPUT);
  pinMode(IN_PIN, OUTPUT);
  
  lcd.begin(LcdColumn, LcdRow); //Inicalizing LCD
  
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE); 
  lcd.setBacklight(HIGH);  //Sets the backlight to maximum
  }

void loop()
{
  delay(1000);
    pinMode(IN_PIN, INPUT);
    digitalWrite(OUT_PIN, HIGH);
    int val = analogRead(IN_PIN);
    digitalWrite(OUT_PIN, LOW);

    if (val < 1000) //If it's pF
    {
      pinMode(IN_PIN, OUTPUT);

      float capacitance = (float)val * IN_CAP_TO_GND / (float)(MAX_ADC_VALUE - val);

      lcd.setCursor(0,0);
      lcd.print("Capacitance = ");
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print(capacitance, 3);// for the best precision
      lcd.print("pF ");
    
    }
    
    else
    {
      pinMode(IN_PIN, OUTPUT);
      delay(1);
      pinMode(OUT_PIN, INPUT_PULLUP);
      unsigned long u1 = micros();
      unsigned long t;
      int digVal;

      do
      {
        digVal = digitalRead(OUT_PIN);
        unsigned long u2 = micros();
        t = u2 > u1 ? u2 - u1 : u1 - u2;
      } 
      
      while ((digVal < 1) && (t < 400000L));

      pinMode(OUT_PIN, INPUT);  
      val = analogRead(OUT_PIN);
      digitalWrite(IN_PIN, HIGH);
      int dischargeTime = (int)(t / 1000L) * 5;
      delay(dischargeTime);   
      pinMode(OUT_PIN, OUTPUT);  
      digitalWrite(OUT_PIN, LOW);
      digitalWrite(IN_PIN, LOW);

      float capacitance = -(float)t / R_PULLUP
                              / log(1.0 - (float)val / (float)MAX_ADC_VALUE);

      lcd.setCursor(0,0);
      lcd.print("Capacitance = ");
      if (capacitance > 1000.0)
      {
        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(0,1);
        lcd.print(capacitance / 1000.0, 2);
        lcd.print("uF ");
   
      }
        
      else
      {
        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(0,1);
        lcd.print(capacitance, 2);
        lcd.print("nF ");

      } 
      
    while (millis() % 1000 != 0);
}
    }

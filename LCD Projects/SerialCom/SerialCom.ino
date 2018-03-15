//load libraries
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

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
#define lcdColumn          16
#define lcdRow             2

//Initialise the LCD
LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

int i;

void setup()
 {
    //Define the LCD as 16 column by 2 rows 
    lcd.begin (lcdColumn,lcdRow);
    
    //Switch on the backlight
    lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);
    Serial.begin(9600);
 }



void loop()
{
  byte hundredByte;
  byte tenByte;
  byte oneByte;
  char serialServo;
  byte serialPos;
  if(Serial.available()>0)
  {
    serialServo=Serial.read();
    char hundredChar=Serial.read();
    char tenChar=Serial.read();
    char oneChar=Serial.read();
    hundredByte=hundredChar-'0';
    hundredByte=hundredByte*100;
    tenByte=tenChar-'0';
    tenByte=tenByte*10;
    oneByte=oneChar-'0';
    serialPos=hundredByte+tenByte+oneByte;
    lcd.print(serialPos);
  }
  if(serialServo=='c')//claw
              {
                lcd.print("claw");
                Serial.println("Claw");
                serialServo=' ';
              }
              else if(serialServo=='h')//hand
              {
                Serial.println("hand");
                serialServo=' ';
              }
              else if(serialServo=='e')//elbow
              {
                Serial.println("elbow");
                
                serialServo=' ';
              }
              else if(serialServo=='p')//shoulderPan
              {
                lcd.setCursor(0,1);
                lcd.print("shoulderPan");
                Serial.println("shoulderPan");
                
                serialServo=' ';
              }
              else if(serialServo=='t')//shoulderTilt
              {
                Serial.println("shoulderTilt");
                
                serialServo=' ';
              }
              delay(500);
}

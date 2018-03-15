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
    
    //goto first column (column 0) and first line (Line 0)
    lcd.setCursor(0,0);
    
    //Print at cursor Location
    lcd.print("Test");
    
    //goto first column (column 0) and second line (line 1)
    lcd.setCursor(0,1);
    lcd.print("");
    for(i=0; i<120;i++)
    {
      lcd.print(i);
      delay(1000);
    }
    
 }
void loop(){ }
 

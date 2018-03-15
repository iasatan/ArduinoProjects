#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR          0x27        //Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN      3
#define En_pin             2
#define Rw_pin             1
#define Rs_pin             0
#define D4_pin             4
#define D5_pin             5
#define D6_pin             6
#define D7_pin             7
#define highT              1
#define lowT               0.5
#define lcdColumn          16
#define lcdRow             2

LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup() 
{
  lcd.begin (lcdColumn,lcdRow);
  //Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);

}

void loop() 
{
  float a = convertVolts(analogRead(0));
  
  lcd.setCursor(0,0);
  lcd.print("Voltage:");
  lcd.setCursor(0,1);
  
  if(a>highT)
  {
    lcd.print("Good ");
    lcd.print(a);
    lcd.print("V");


  }
  else if(a>lowT)
  {
    lcd.print("Ok ");
    lcd.print(a);
    lcd.print("V");
  }
  else
  {
    lcd.print("Bad ");
    lcd.print(a);
    lcd.print("V");
  }
  delay(1000);
  lcd.clear();
}

float convertVolts(int b){
float volt;
volt=b;
volt=volt/1024;
volt=volt*5;
return volt;
}

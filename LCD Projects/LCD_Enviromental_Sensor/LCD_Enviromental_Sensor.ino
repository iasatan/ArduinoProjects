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
#define sensorPin          1 //Carbon Dioxide sensor pin
#define buttonPin          2
   
//Initialise the LCD
LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
int sensorValue;
String sensorName;
int sensorType;
String warning;
int buttonState;


void setup()
 {
    //Define the LCD as 16 column by 2 rows 
    lcd.begin (lcdColumn,lcdRow);
    
    //Switch on the backlight
    lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);
    
    //goto first column (column 0) and first line (Line 0)
    lcd.setCursor(0,0);
    sensorName="co=";
    sensorType=2;
    warning="";
    pinMode(buttonPin, INPUT);
}


void loop(){
  buttonState = digitalRead(buttonPin);
  sensorValue = analogRead(sensorPin);       // read analog input pin 0
  if (buttonState == HIGH) {
    if( sensorType==1){
      sensorName="co=";
      sensorType=2;  
    }
    else if(sensorType==2){
      sensorName="co2=";
      sensorType=1;
    }
  }
  lcd.setCursor(0,0);
  if(sensorType==1){
    warning=carbonDioxideWarning(sensorValue);
  }
  if(sensorType==2){
    warning=carbonMonoxideWarning(sensorValue);
  }
  lcd.setCursor(0,0);
  lcd.print(sensorName);
  lcd.print(sensorValue,DEC);
  lcd.print(" PPM");
  lcd.println("       "); 
  lcd.print("  ");
  lcd.setCursor(0,1);
  lcd.print(warning);
  lcd.print("       ");
  
  delay(500);
}

String carbonMonoxideWarning(int ppm){
  if(ppm>1600){
    return "Death";
  }
  if(ppm>800){
    return "Run or Die";
  }
  if(ppm>400){
    return "Headache";
  }
  if(ppm>200){
    return "Bad Air";
  }
  if(ppm>50){
    return "Good Air";
  }
  return "enjoy";
}

String carbonDioxideWarning(int ppm){
  if(ppm>40000){
    return "Death";
  }
  if(ppm>5000){
    return "Toxic";
  }
  if(ppm>2000){
    return "Headache";
  }
  if(ppm>1000){
    return "shit air";
  }
  if(ppm>350){
    return "good air";
  }
  return "enjoy";
  
}

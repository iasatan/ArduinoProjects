//load libraries
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
//Define variables 

#define I2C_ADDR                  0x27        //Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN             3 
#define En_pin                    2
#define Rw_pin                    1
#define Rs_pin                    0
#define D4_pin                    4
#define D5_pin                    5
#define D6_pin                    6
#define D7_pin                    7
#define lcdColumn                 16
#define lcdRow                    2
#define joystickPanPin            A0
#define joystickClawPin           A1
#define servoPanPin               11
#define servoClawPin              12

//Initialise the LCD
LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
Servo panServo;      
Servo clawServo;  

int i;
int servoPanPosition = 90;
int servoClawPosition = 90;
int joystickPanSpeed = 0;
int joystickClawSpeed = 0;


void setup()
{
  pinMode(servoPanPin, OUTPUT);
  pinMode(servoClawPin, OUTPUT);
  panServo.attach(servoPanPin);
  clawServo.attach(servoClawPin);
  lcd.begin (lcdColumn,lcdRow);
    
  //Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
}


void loop()
{
  joystickPanSpeed = (analogRead(joystickPanPin) - 468) / 50;
    // -512 to provide equal +/- numbers
  joystickClawSpeed = (analogRead(joystickClawPin) - 511) / -50;
    // negative 50 to reverse direction

  servoPanPosition = constrain((servoPanPosition + joystickPanSpeed), 0, 180);
  servoClawPosition = constrain((servoClawPosition + joystickClawSpeed), 0, 180);
    // constarin function to not exceed servo limits
  lcd.setCursor(0,0);
  lcd.print("Claw pos: ");
  lcd.print(servoClawPosition);
  lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print("Pan pos: ");
  lcd.print(servoPanPosition);
  lcd.print(" ");

  panServo.write(servoPanPosition);
  clawServo.write(servoClawPosition);

  delay(100);
    // adjustable for overall speed
}

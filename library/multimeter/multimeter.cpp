/*************************************************************************
Author:   Sátán Ádám <satanadam@outlook.com>
For Arduinos
**************************************************************************/


#include "Arduino.h"
#include "multimeter.h"
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

const float IN_STRAY_CAP_TO_GND = 24.48;
const float IN_CAP_TO_GND = IN_STRAY_CAP_TO_GND;
const float R_PULLUP = 34.8;
const short MAX_ADC_VALUE = 1023;


/*************************************************************************
Calculates the distance, using an ultrasonic distance sensor
*************************************************************************/

void calculateCapacitance(byte OUT_PIN, byte IN_PIN, LiquidCrystal_I2C lcd)
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

		lcd.setCursor(0, 0);
		lcd.print("Capacitance = ");
		lcd.setCursor(0, 1);
		lcd.print("                ");
		lcd.setCursor(0, 1);
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

		lcd.setCursor(0, 0);
		lcd.print("Capacitance = ");
		if (capacitance > 1000.0)
		{
			lcd.setCursor(0, 1);
			lcd.print("                ");
			lcd.setCursor(0, 1);
			lcd.print(capacitance / 1000.0, 2);
			lcd.print("uF ");

		}

		else
		{
			lcd.setCursor(0, 1);
			lcd.print("                ");
			lcd.setCursor(0, 1);
			lcd.print(capacitance, 2);
			lcd.print("nF ");

		}

		while (millis() % 1000 != 0);
	}
}

void calculateBatteryState(byte BATTERY_PIN, LiquidCrystal_I2C lcd)
{
	float highT = 1;
	float lowT = 0.5;
	float a = convertVolts(analogRead(BATTERY_PIN));
	lcd.setCursor(0, 0);
	lcd.print("Feszultseg:");
	lcd.setCursor(0, 1);

	if (a>highT)
	{
		lcd.print("Jo ");
		lcd.print(a);
		lcd.print("V");


	}
	else if (a>lowT)
	{
		lcd.print("Megfelel ");
		lcd.print(a);
		lcd.print("V");
	}
	else
	{
		lcd.print("Rossz ");
		lcd.print(a);
		lcd.print("V");
	}
	delay(1000);
	lcd.clear();
}
/*************************************************************************
Calculates the voltage
*************************************************************************/
float convertVolts(int analogRead)
{
	//I don't know why, but if I use it in a single command, it don't work
	float volt;
	volt = analogRead;
	volt = volt / 1024;
	volt = volt * 5;
	return volt;
}
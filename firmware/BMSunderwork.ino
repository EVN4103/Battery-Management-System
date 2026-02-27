#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "ACS712.h"

LiquidCrystal_I2C lcd(0x27,16,2);

float adc_voltage = 0;
float voltage = 0;
float battery_voltage = 0;

ACS712 ACS(A1, 5.0, 1023, 66);

void setup()
{
  pinMode(2, OUTPUT);
  delay(2000);
  digitalWrite(2, HIGH);   // relay ON

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("BMS ON");
  delay(2000);
  lcd.clear();

  // ACS712 zero calibration (no load)
  ACS.autoMidPointDC(100);
}

void loop()
{
  // -------- Voltage read ----------
  adc_voltage = analogRead(A0);
  voltage = adc_voltage * 5.0 / 1023.0;
  battery_voltage = (voltage * 3.0)-1.65;   // for 3x10k divider

  // -------- Current read ----------
  int mA = ACS.mA_DC();
  float amps = mA / 1000.0;

  if(amps < 0.1 && amps > -0.25)
  amps = 0;

  // -------- Voltage fault ----------
  if (battery_voltage > 15)
  {
    digitalWrite(2, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("OVER VOLTAGE");
    delay(5000);
  }

  else if (battery_voltage < 10)
  {
    digitalWrite(2, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("UNDER VOLTAGE");
    delay(5000);
  }

  // -------- Current fault ----------
  else if (amps > 3)
  {
    digitalWrite(2, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("OVER CURRENT");
    delay(5000);
  }

  // -------- Normal condition ----------
  
}

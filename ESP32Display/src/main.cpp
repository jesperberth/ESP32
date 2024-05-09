#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(1,0);
  lcd.print("System Ready...");
  Serial.begin(921600);
  Serial.println("System Ready...");
}

void loop() {
  delay(3000);
  Serial.println("Start loop");
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Kom til ARROW");
  lcd.setCursor(1,1);
  lcd.print("Inspiration Day");
  delay(3000);

  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("14 - 15");
  lcd.setCursor(5,1);
  lcd.print("November");
  delay(3000);

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("ARROW Tech Hub");
  lcd.setCursor(0,1);
  lcd.print("_-_-_-_-_-_-_-_-");
  delay(3000);
}
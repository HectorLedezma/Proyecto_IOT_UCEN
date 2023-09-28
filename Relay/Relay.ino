#include "Wire.h"
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);
int relay1 = D3; // for ESP8266 microcontroller
int relay2 = D4;
void setup() {
  lcd.init();
  lcd.backlight();
  // put your setup code here, to run once:
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("1    ON");
  lcd.setCursor(2, 1);
  lcd.print("2    OFF");
  delay(4000);

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("1    OFF");
  lcd.setCursor(2, 1);
  lcd.print("2    ON");
  delay(4000);
}

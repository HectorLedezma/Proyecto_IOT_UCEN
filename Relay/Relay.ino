#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#define SensorPin D0

LiquidCrystal_I2C lcd(0x27, 16, 2);
int relay1 = D3; // for ESP8266 microcontroller
int relay2 = D4;

#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK "your-password"
#endif

const char* ssid = "Redmi 9C";
const char* password = "012345678";

//const char* ssid = "Zeroora";
//const char* password = "notieneclave";

const char* host = "djxmmx.net";
const uint16_t port = 17;


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  // put your setup code here, to run once:
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

}

void loop() {
  float sensorValue = analogRead(SensorPin);
  Serial.println(sensorValue);
  if(sensorValue == 0.0){
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
  }else{
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
  }
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Humedad: "+String(sensorValue));
  // put your main code here, to run repeatedly:
  /*
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("1    ON");
  lcd.setCursor(2, 1);
  lcd.print("2    OFF");
  delay(4000);

  
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("1    OFF");
  lcd.setCursor(2, 1);
  lcd.print("2    ON");
  */
  delay(2000);
}

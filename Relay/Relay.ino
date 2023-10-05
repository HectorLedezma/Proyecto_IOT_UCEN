#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#define SensorPin D0

//#include "DHT.h" 
//#define PinSensor    // Pin digital al que se conecta el sensor
//#define Tipo DHT11    // Tipo de sensor

#include <ESP8266WiFi.h>
#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK "your-password"
#endif

LiquidCrystal_I2C lcd(0x27, 16, 2);
int relay1 = D3; // for ESP8266 microcontroller
int relay2 = D4;

const char* ssid = "Redmi 9C";
const char* password = "012345678";

//const char* ssid = "Zeroora";
//const char* password = "notieneclave";

const char* host = "djxmmx.net";
const uint16_t port = 17;
String state = "";


//DHT dht(PinSensor, Tipo);
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  //dht.begin();
}

void loop() {
  float sensorValue = analogRead(SensorPin);
  Serial.println(sensorValue);
  lcd.clear();
  if(sensorValue == 0.0){
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
    state = "seca";
  }else{
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
    state = "humedo";
  }
  lcd.setCursor(2, 0);
  lcd.print("Planta "+state);
  delay(2000);
  /*
  delay(5000);   
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();
  Serial.print("Humedad: "); 
  Serial.println(humedad);
  Serial.print("Temperatura:"); 
  Serial.println(temperatura);
  */
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
  
}

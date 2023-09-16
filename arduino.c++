#include <ArduinoJson.h>

#include "DHT.h"
#define DHTPIN  7 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int ldr = A0;
int valorldr = 0;

void setup() 
{
    Serial.begin(9600);
    dht.begin();
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() 
{
  float temp = dht.readTemperature();
  
  float umi = dht.readHumidity();

  json["temperatura"] = temp;
  json["umidade"] = umi;

  valorldr=analogRead(ldr);
  json["poluentes"] = valorldr;

  serializeJson(json, Serial);
  Serial.println();
  
  delay(5000);
}

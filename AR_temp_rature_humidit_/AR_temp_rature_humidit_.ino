// onimporte les librairie 
#include "DHT.h"

//digital pin connected to the DHT sensor
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
  
}

void loop() {
  // on met un delay
  delay(2000);

  //reading temperature or humidity takes about 250ms
  // Sensor readings may alosi be up to 2s 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  Serial.print(h);
  // read temperature as Celsius (the default)
  float t = dht.readTemperature();
  Serial.print(t);

  //check if any reads failed and exit early (to try again)
  if  (isnan(h) || isnan(t)){
    Serial.println(F("echec de lecture"));
    return;
  }

  Serial.print(F("Humidite :"));
  Serial.print(h);
  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("°C"));
  

}

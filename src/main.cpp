#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>

void getAht10Values();
void printValues();

Adafruit_AHTX0 aht10;
sensors_event_t aht10Temp, aht10Hum;

float temperature = -99;
float humidity = -99;

void setup() {
    Wire.begin(8,9);
    Serial.begin(115200);
    aht10.begin();

}

void loop() {
    byte address = 0x38;
    getAht10Values();
    printValues();
    delay(5000);

}

void getAht10Values() {
  aht10.getEvent(&aht10Hum, &aht10Temp);// populate temp and humidity objects with fresh data
  temperature = aht10Temp.temperature;
  humidity = aht10Hum.relative_humidity;
/*
  Serial.println(F("AHT10 Values"));
  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.println(F(" *C"));

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.println(F(" %"));
  Serial.println();
  */
}

void printValues() {
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" *C");

  // Convert temperature to Fahrenheit
  /*Serial.print("Temperature = ");
  Serial.print(1.8 * bme.readTemperature() + 32);
  Serial.println(" *F");*/

  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");
  Serial.println();
}

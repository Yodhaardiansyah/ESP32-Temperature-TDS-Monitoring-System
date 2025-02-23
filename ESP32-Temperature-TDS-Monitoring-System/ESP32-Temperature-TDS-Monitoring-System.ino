/*
 * ESP32 Temperature & TDS Monitoring System
 * Developed by: Yodha Ardiansyah
 * Website: https://arunovasi.my.id
 * Last Updated: February 2025
 */

#include <OneWire.h>
#include <DallasTemperature.h>

// Pin Configuration
#define DS18B20_PIN 15   // DS18B20 Sensor Pin (e.g., GPIO 15)
#define TDS_PIN 4        // TDS Sensor Pin (GPIO 4 for analog input)

// OneWire & DallasTemperature Setup for DS18B20
OneWire oneWire(DS18B20_PIN);
DallasTemperature sensors(&oneWire);

// Variables for TDS Sensor
float tdsValue = 0;
float voltage = 0;
float tdsFactor = 0.5;  // Adjust TDS factor based on sensor calibration

void setup() {
  // Initialize Serial Communication
  Serial.begin(115200);
  
  // Initialize DS18B20 Sensor
  sensors.begin();
  
  // Startup Message
  Serial.println("ESP32 Temperature & TDS Monitoring Initialized.");
}

void loop() {
  // Read Temperature from DS18B20
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  
  if (temperature != -127.00) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
  } else {
    Serial.println("Error: DS18B20 sensor not detected or invalid!");
  }
  
  // Read Analog Value from TDS Sensor
  int analogValue = analogRead(TDS_PIN);
  
  // Convert Analog Value to Voltage (0-3.3V for ESP32)
  voltage = analogValue * (3.3 / 4095.0);  // 12-bit ADC scaling for ESP32
  
  // Calculate TDS Value (mg/L or ppm)
  tdsValue = (voltage * tdsFactor) * 1000;  // TDS in ppm
  
  Serial.print("TDS Value: ");
  Serial.print(tdsValue);
  Serial.println(" ppm");
  
  // Wait before next reading
  delay(2000);
}

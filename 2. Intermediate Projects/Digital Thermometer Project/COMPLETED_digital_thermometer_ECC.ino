/*
Digital Thermometer Project
Build & Code: Arduino Workshop

A. D'Alesio, C. Mendes
© Electronics & Computing Club (ECC) 2026
*/

// Importing libraries for reading temperature data from sensor
#include <OneWire.h>
#include <DallasTemperature.h>

// Simple pin mappings via constants (read-only variables)
const int tempPin = 2;
const int barLEDPins[10] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4};

// Variable to store bar LED level (to be used later on)
int previousBarLevel = 0;

// Initialize 1-Wire temperature sensor communication
OneWire oneWire(tempPin);
DallasTemperature sensors(&oneWire);

void setup() {
  pinMode(tempPin, INPUT);    // Define the pin mode for temperature sensor

  // Define the pin mode for bar LED pins
  for (int x = 0; x <= 9; x++)
    pinMode(barLEDPins[x], OUTPUT);

  Serial.begin(9600);         // Initialize the serial monitor with a specified baud rate
  sensors.begin();            // Initialize the temperature sensor to begin capturing values
}

void loop() {
  int temp;   // Create a variable to store temperature data

  sensors.requestTemperatures();      // Capture data from sensor
  temp = sensors.getTempCByIndex(0);  // Store data in 'temp' variable 
  delay(1000);  // Brief delay between captures

  Serial.println(temp);   // Print the current temperature reading to the serial monitor

  int barLevel = map(temp, 20, 30, 0, 9);   // New variable with mapped values (20-24°C range to 0-9 bar LED segments)

  // If temperature increased, start turning bar LED segments ON
  if (barLevel > previousBarLevel) {
    for (int x = previousBarLevel; x <= barLevel; x++)
      digitalWrite(barLEDPins[x], HIGH);
  }

  // If temperature decreased, start turning LED segments OFF
  if (barLevel < previousBarLevel) {
    for (int x = previousBarLevel; x > barLevel; x--)
      digitalWrite(barLEDPins[x], LOW);
  }

  // Remember current bar level for next loop
  previousBarLevel = barLevel;

  Serial.println(barLevel + 1);   // Print the bar LED value to the serial monitor
  Serial.println();   // Print blank line
}
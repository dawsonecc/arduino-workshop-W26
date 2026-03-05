/*
Car Proximity Alarm Project
Build & Code: Arduino Workshop

Charles Ross
© Electronics & Computing Club (ECC) 2026
*/

// Library for the ultrasonic sensor
#include <NewPing.h>

// Define the pin names
const int triggerPin = 12;
const int echoPin = 13;
const int alarmPin = 7;

// Define a variable for distance
unsigned long distance;

// Create the sonar object (our ultrasonic sensor)
NewPing sonar(triggerPin, echoPin, 200);

void setup() {

  // Alarm pin needs to be active
  pinMode(alarmPin, OUTPUT);

  // initialize serial console (Ctrl-Shift-M to turn it on)
  Serial.begin(115200);

}

void loop() {
  // 💡 Get a cm distance to wall from ultrasonic sensor

  // If the distance is far enough for the sensor to detect (it would be 0 if the object was too far)
  if(distance != 0) {

    // Print it
    Serial.print("Distance: "); Serial.println(distance);

    // 💡 Make a decision based on if the object is too close

    // 💡 If it is, activate the alarm (send a 1 to the alarm pin, wait a bit,then a 0 to turn it off)

  }

}

/*
Car Proximity Alarm Project
Build & Code: Arduino Workshop

Charles Ross
© Electronics & Computing Club (ECC) 2026
*/


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
  Serial.begin(115200);

}

void loop() {
  // Get a cm distance to wall from ultrasonic sensor
  distance = sonar.ping_cm();

  // If the distance is not out of bounds
  if(distance != 0) {
    // Print it
    Serial.print("Distance: "); Serial.println(distance);

    // Initial warning if the wall is within 100cm range
    if(distance < 100){
      Serial.println("Careful...");
    }

    // If the wall is within 50cm, activate the alarm
    if(distance < 50){
      // 0.5s active, 0.5s inactive (can be simplified to be constantly active)
      delay(500);
      digitalWrite(alarmPin, HIGH);
      delay(500);
      digitalWrite(alarmPin, LOW);
    }

  }

}

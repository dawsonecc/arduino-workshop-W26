/*
Car Proximity Alarm Project - MANUAL SENSOR CODE
Build & Code: Arduino Workshop

Charles Ross
© Electronics & Computing Club (ECC) 2026
*/


// Define the pin names
const int triggerPin = 12;
const int echoPin = 13;
const int alarmPin = 7;

// Define a variable for pulse duration and distance detected
unsigned long duration;
unsigned long distance;



void setup() {
  // Alarm pin needs to be active
  pinMode(alarmPin, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  // Get a cm distance to wall from ultrasonic sensor
  distance = ping();

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

unsigned long ping() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);

  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance = duration * 0.034 / 2;

  return distance;
}


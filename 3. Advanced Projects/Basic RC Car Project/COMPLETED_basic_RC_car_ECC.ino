/*
Basic RC Car Project
Build & Code: Arduino Workshop

A. D'Alesio
© Electronics & Computing Club (ECC) 2026
*/

// Pin mappings
const int DirPin1 = 2;
const int DirPin2 = 3;
const int MotorPin = 5;
const int PotPin = A0;
const int DirSwitchPin = 4;

void setup() {
  // Configuring I/O
  pinMode(DirPin1, OUTPUT);
  pinMode(DirPin2, OUTPUT);
  pinMode(MotorPin, OUTPUT);
  pinMode(DirSwitchPin, INPUT_PULLUP);

  Serial.begin(115200);   // Start the serial monitor with a specified baud rate
}

void loop() {
  int RawSpeed = analogRead(PotPin);    // Set the raw readings from the PotPin to a variable
  int SetSpeed = map(RawSpeed, 99, 1023, 115, 255);   // Map the raw potentiometer values to an acceptable range for controlling motor speed
  int SpinDir = digitalRead(DirSwitchPin);    // Read the status of the DirSwitchPin and map value to a variable

  analogWrite(MotorPin, SetSpeed);    // Set the motor speed

  // Print motor settings to the serial monitor
  Serial.print("Motor Speed (115-255): ");
  Serial.println(SetSpeed);
  Serial.print("Spin Direction: ");
  
  // Conditional statement to change motor direction and print spin direction based on DirSwitchPin
  if (SpinDir) {
    digitalWrite(DirPin1, HIGH);
    digitalWrite(DirPin2, LOW);
    Serial.println("Clockwise");
  }
  else {
    digitalWrite(DirPin1, LOW);
    digitalWrite(DirPin2, HIGH);
    Serial.println("Counterclockwise");
  }

  Serial.println("");   // Print a blank line for readability
  _delay_ms(250);   // Wait a brief moment before reading, setting, and printing values again
}

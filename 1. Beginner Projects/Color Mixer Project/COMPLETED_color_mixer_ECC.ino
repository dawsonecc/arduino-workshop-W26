/*
Color Mixer Project
Build & Code: Arduino Workshop

A. D'Alesio
© Electronics & Computing Club (ECC) 2026
*/

// Pin mappings for RGB LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  Serial.begin(115200);   // Start the serial monitor with a specified baud rate
}

void loop() {
  // Pin mappings for potentiometers
  int pot0 = analogRead(A0);
  int pot1 = analogRead(A1);
  int pot2 = analogRead(A2);
  
  // Converting the ~0-1023 range to 0-255 for driving the RGB LED
  int redValue = map(pot0, 525, 1023, 0, 255);
  int greenValue = map(pot1, 96, 1023, 0, 255);
  int blueValue = map(pot2, 87, 1023, 0, 255);

  delay(100);   // Brief delay between acquisition cycles

  // Printing RGB values to serial monitor
  Serial.print(redValue);
  Serial.print(", ");
  Serial.print(greenValue);
  Serial.print(", ");
  Serial.println(blueValue);

  // Sending RGB values off to the LED
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
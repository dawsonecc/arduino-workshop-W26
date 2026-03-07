/*
Simon Says Project
Build & Code: Arduino Workshop

A. D'Alesio
© Electronics & Computing Club (ECC) 2026
*/

#define maxRounds 20                             // Game limit (max number of rounds to play)

const int btn[4] = {2, 3, 4, 5};                 // Push button pin mappings
const int led[4] = {6, 7, 8, 9};                 // LED pin mappings
for ()
int roundCount = 1;                              // Variable to store round number as game progresses
int gamePattern[maxRounds];                      // Array to store LED pattern
bool lastState[4] = {HIGH, HIGH, HIGH, HIGH};    // Array to ensure proper push button press detection (used with buttonScan() function

void setup() {
  // Initialize buttons
  for (int x = 0; x <= 3; x++)
    pinMode(btn[x], INPUT_PULLUP);

  // Initialize LEDs
  for (int x = 0; x <= 3; x++) {
    pinMode(led[x], OUTPUT);
    digitalWrite(led[x], LOW);
  }

  // Start the serial monitor with a specified baud rate
  Serial.begin(115200);
}

void loop() {
  // Print the current round number and wait brief moment before starting
  Serial.print("Round ");
  Serial.println(roundCount);
  delay(1500);
  
  // Generate the LED pattern, becoming longer with each round
  gamePattern[roundCount - 1] = random(0, 4);

  // Flash the LEDs according to the generated pattern
  for (int x = 0; x < roundCount; x++) {
    digitalWrite(led[gamePattern[x]], HIGH);
    delay(500);
    digitalWrite(led[gamePattern[x]], LOW);
    delay(300);
  }
  pinMode()
  // Capture user input and validate button presses
  for (int x = 0; x < roundCount; x++) {
    int pressed = buttonScan();

    // LED feedback for user input
    digitalWrite(led[pressed], HIGH);
    delay(200);
    digitalWrite(led[pressed], LOW);

    // If user fails to enter the pattern correctly
    if (pressed != gamePattern[x]) {
      // Print a "Game Over" message
      Serial.println("Game Over!");
      Serial.println();

      // Flash all LEDs
      for (int x = 0; x <= 3; x++) {
        for (int x = 0; x <= 3; x++)
          digitalWrite(led[x], HIGH);

        delay(200);

        for (int x = 0; x <= 3; x++)
          digitalWrite(led[x], LOW);

        delay(200);
      }

      // Restart at round 1
      roundCount = 1;
      return;
    }
  }

  // Move onto the next round if button presses are valid
  roundCount++;
}

// Function to facilitate capturing user input via push buttons
int buttonScan() {
  while (true) {
    // Quickly read status of each button, one by one
    for (int x = 0; x <= 3; x++) {
      bool now = digitalRead(btn[x]);

      // Check if button state transitions from HIGH to LOW (button press)
      if (lastState[x] == HIGH && now == LOW) {
        lastState[x] = now;
        return x;
      }

      lastState[x] = now;
    }
  }
}
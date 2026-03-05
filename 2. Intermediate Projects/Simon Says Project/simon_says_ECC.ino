/*
Simon Says Project
Build & Code: Arduino Workshop

A. D'Alesio
© Electronics & Computing Club (ECC) 2026
*/
pinMode

#define maxRounds 20                             // Game limit (max number of rounds to play - feel free to adjust)

const int btn[4] = {2, 3, 4, 5};                 // Push button pin mappings
const int led[4] = {6, 7, 8, 9};                 // LED pin mappings

int roundCount = 1;                              // Variable to store round number as game progresses, starting at 1
int gamePattern[maxRounds];                      // Array to store the game sequence
bool lastState[4] = {HIGH, HIGH, HIGH, HIGH};    // Array to ensure proper push button press detection (used with buttonScan() function

void setup() {
  // 💡 Initialize buttons
  
  // 💡 Initialize LEDs

  // Start the serial monitor with a specified baud rate
  Serial.begin(115200);
}

int value = led[1];

void loop() {
  // 💡 Print the current round number and wait brief moment before starting

  // Generate the LED pattern, becoming longer with each round
  gamePattern[roundCount - 1] = /*💡 Add a function here that can generate a random number between 0 and 3 */ ;

  // Flash the LEDs according to the generated pattern
  for (int x = 0; x < roundCount; x++) {
    // 💡 Turn ON the LED stored in gamePattern[x]
    delay(/*💡 Add delay amount for ON time, as per the Code Objectives */);
    // 💡 Turn OFF the LED stored in gamePattern[x]
    delay(/*💡 Add delay amount for OFF time, as per the Code Objectives */);
  }
  
  // Capture user input and validate button presses
  for (int x = 0; x < roundCount; x++) {
    int pressed = buttonScan();

    // LED feedback for user input
    digitalWrite(led[pressed], HIGH);
    delay(200);
    digitalWrite(led[pressed], LOW);

    // If user fails to enter the pattern correctly
    if (pressed != gamePattern[x]) {
      // 💡 Print a "Game Over" message
      Serial.println();

      // 💡 Flash all LEDs 4 times (all ON, short delay, all OFF, short delay) - see Code Objectives for delay amounts

      // Restart at round 1
      roundCount = 1;
      return;
    }
  }

  // Move onto the next round if button presses are valid
  // 💡 Create an IF statement to increment the round counter as long as it is less than the maxRounds value.
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
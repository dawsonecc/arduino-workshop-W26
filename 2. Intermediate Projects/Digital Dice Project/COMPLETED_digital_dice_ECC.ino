/*
Digital Dice Project
Build & Code: Arduino Workshop

Charles Ross
© Electronics & Computing Club (ECC) 2026
*/

const int ledPins[4] = {2,3,4,5}; // Set the LED pin numbers

const int buttonPin = 10; // Set the button pin number

bool buttonState = false; // Check the state of the button
int numberDisplayed; // Store the number to be displayed

void setup() {
  pinMode(ledPins[0], OUTPUT); // Initialize all LED pins (NO FOR LOOP FOR SIMPLICITY)
  pinMode(ledPins[1], OUTPUT);
  pinMode(ledPins[2], OUTPUT);
  pinMode(ledPins[3], OUTPUT);

  pinMode(buttonPin, INPUT); // Initialize button pin

  outputToPins(0); // Initialize LED pins as 0

}

void loop() {
  buttonState = digitalRead(buttonPin); // Initial read of the button

  if(buttonState){ // if button is pressed, start the dice

    numberDisplayed = random(0,10); // Random number generated for the dice

    for(int i = 0; i < 8; i++){ // Random number sequence
        outputToPins(random(0,10));
        delay(100);
    }

    outputToPins(numberDisplayed); // Display generated number

    do {
      buttonState = digitalRead(buttonPin); // Check for a button press to restart dice roll
    } while(!buttonState);
  }
}

// We should probably just give out this function 
void outputToPins(int numberOutput){
  for(int i = 0; i < 4; i++){
    digitalWrite(ledPins[i],(bool)(numberOutput & 1));
    numberOutput = numberOutput >> 1;
  }
}

/*
Digital Dice Project
Build & Code: Arduino Workshop

Charles Ross
© Electronics & Computing Club (ECC) 2026
*/

// Change LED pin numbers if you haven't done exactly as the diagram shows
// FORMAT: lowest digit to highest digit
const int ledPins[4] = {2,3,4,5}; 

// Set button pin number
const int buttonPin = 10; 

bool buttonState = false; // To check the state of the button
int numberDisplayed; // To store the number to be displayed

void setup() {
  // Initialize the LED pins
  pinMode(ledPins[0], OUTPUT); 
  pinMode(ledPins[1], OUTPUT);
  pinMode(ledPins[2], OUTPUT);
  pinMode(ledPins[3], OUTPUT);

  pinMode(buttonPin, INPUT); // Initialize the button pin

  outputToPins(0); // Initialize to display 0 (This is the custom function at line 50)

}

void loop() {
  // 💡 Read the button pin and store it in buttonState

  if(buttonState){ // if button is pressed, start the dice

    // 💡 Generate a random number for the dice

    // 💡 Create a small animation (optional)

    // 💡 Display generated number

    // This loop will stall the program until it reads a button press again
    do {
      // 💡 Read the button pin inside the loop (or else the program stalls forever)
    } while(!buttonState);
  }
}

// This function is going to output whatever number you give it to the pins specified in ledPins[]
void outputToPins(int numberOutput){
  for(int i = 0; i < 4; i++){
    digitalWrite(ledPins[i],(bool)(numberOutput & 1));
    numberOutput = numberOutput >> 1;
  }
}

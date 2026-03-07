/*
Mini Synthesizer Project - Arpeggiator
Build & Code: Arduino Workshop

Charles Ross
© Electronics & Computing Club (ECC) 2026
*/

// Lookup table for notes (C5 - G5)
const unsigned int notes[7] = {
  523,587,659,698,784,880,988
};

// Mapped pins for each notes
const int notePins[7] = {
  4,5,6,7,8,9,10
};

// Pin for buzzer input
const int buzzerPin = 3;

// Frequencies that will be output
unsigned int outputFrequency[3] = {0,0,0};

void setup() {
  // Initialize all note pins as inputs
  for(int i = 0; i < 7; i++){
    pinMode(notePins[i],INPUT);
  }

  // Initialize buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  //Reset frequency outputs to 0
  outputFrequency[0] = 0;
  outputFrequency[1] = 0;
  outputFrequency[2] = 0;
  
  // Counter to keep track of buttons
  int j = 0;

  // Check all note pins for an input
  for(int i = 0; i < 7; i++){

    // If a pushbutton (i.e. a note) was pressed
    if(digitalRead(notePins[i]) == 1){
      // Whatever frequency on the same position as the pin in the lookup table is output for 1/4 note
      outputFrequency[j] = notes[i];
      // Button counter increased
      j++;
    }
    // Only 3 buttons can be pressed at once
    if (j == 3){
      j = 2;
      break;
    }

  }
  // Main arpeggiator function - no break statements means case 2 can go into case 1 and case 0, etc..
  switch(j){
    case 2: tone(buzzerPin,outputFrequency[2],100); // If all three notes pressed, start here
    delay(100);
    case 1: tone(buzzerPin,outputFrequency[1],100); // If two notes pressed, start here
    delay(100);
    case 0: tone(buzzerPin,outputFrequency[0],100); // If three notes pressed, go here
    delay(100);
    break;
  }
}

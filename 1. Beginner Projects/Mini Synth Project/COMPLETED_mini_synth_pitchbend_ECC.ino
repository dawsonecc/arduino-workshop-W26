/*
Mini Synthesizer Project - pitchbend
Build & Code: Arduino Workshop

Charles Ross
© Electronics & Computing Club (ECC) 2026
*/

// Lookup table for notes (C5 - G5)
const unsigned int notes[9] = {
  523,587,659,698,784,880,988,1046,1108
};

// Mapped pins for each notes
const int notePins[7] = {
  4,5,6,7,8,9,10
};

// Pin for buzzer output and pitch wheel input
const int buzzerPin = 3;
const int pitchPin = A0;

// Frequency that will be output
unsigned int outputFrequency = 0;

// Pitch wheel input value
int pitchBend = 0;

void setup() {
  // Initialize all note pins as inputs
  for(int i = 0; i < 7; i++){
    pinMode(notePins[i],INPUT);
  }

  // Initialize buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  pinMode(pitchPin,INPUT);

}

void loop() {
  //Reset frequency output to 0
  outputFrequency = 0;

  // Converts analog value to +-100Hz pitch bend
  pitchBend = map(analogRead(pitchPin),0,1024,-100,100);
  
  // Check all note pins for an input
  for(int i = 0; i < 7; i++){

    // If a pushbutton (i.e. a note) was pressed
    if(digitalRead(notePins[i]) == 1){

      // Whatever frequency on the same position as the pin in the lookup table is output for 1/4 note
      // ADDED pitch bend modifier
      outputFrequency = notes[i] + pitchBend;

      tone(buzzerPin,outputFrequency,100);
      delay(100); // Note plays in parallel with code being run, so delay is necessary
    }
  }
}

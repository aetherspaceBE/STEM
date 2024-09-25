#include "pitches.h"//tone library

// CONSTANTS
//Inputs: 
// On-off switch to start the game
const byte on_off = 2;
// the start zone
const byte StartPin = 3;
// end zone
const byte EndPin = 4;
// If the wire is touched 
const byte FailPin = 5;
// The microswitch to see if box is closed
const byte Lid = 7;
//Outputs: 
// The buzzer, goes off when wire is touched
const byte Buzzer = 10;
//The red led
const byte RedLed = 11;

//The green led
const byte GreenLed = 12;

//GLOBALS
// keep track of the state of the game
enum GameState {BEGIN, IN_PROGRESS, END};
GameState gamestate = GameState :: BEGIN;
volatile int state = LOW;

void Toneone() {
    int melody4[] = {  NOTE_F5, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_GS5};

    int noteDurations[] = {4, 8, 4, 8, 8, 8, 4};
    for (int thisNote = 0; thisNote < 7; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(Buzzer, melody4[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(Buzzer);
  }
}

void Tonetwo() {
  int melody2[] = {NOTE_DS8, NOTE_DS8,};
  //int melody2[] = {NOTE_GS7, NOTE_DS8, NOTE_GS7, 0, NOTE_DS8, NOTE_DS8, 0, NOTE_GS7, NOTE_GS7};

  int noteDurations[] = {8, 4};

  for (int thisNote = 0; thisNote < 2; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(Buzzer, melody2[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(Buzzer);
  }
}
void Tonethree() {
  int melody2[] = {NOTE_F5, NOTE_C6};
  //int melody2[] = {NOTE_GS7, NOTE_DS8, NOTE_GS7, 0, NOTE_DS8, NOTE_DS8, 0, NOTE_GS7, NOTE_GS7};

  int noteDurations[] = {8, 8};

  for (int thisNote = 0; thisNote < 2; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(Buzzer, melody2[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(Buzzer);
  }
}
int changeState() { // Simulates a positive flank detection
  int newState = digitalRead(Lid); // read the current state of the input pin
  if (newState == LOW && state == HIGH) { // check if the new state is low and the previous state was high
    return 1;// print message to serial monitor
  }
  state = newState; // update the state variable
  return 0;
}


void setup() {
  // set pins to the correct mode
  pinMode(StartPin, INPUT_PULLUP);
  pinMode(EndPin, INPUT_PULLUP);
  pinMode(FailPin, INPUT_PULLUP);
  pinMode(Lid, INPUT_PULLUP);

  pinMode(Buzzer, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  // begin serial connection with computer, 9600 bits per second 
  Serial.begin(9600);

}

void loop() {
  int oxo = changeState();
  switch(gamestate){
    case GameState::BEGIN:
      // actions in this state
      digitalWrite(GreenLed, LOW);
      digitalWrite(RedLed, HIGH);
      // check if we are in another state
      delay(100);
      if (digitalRead(Lid)){
        Tonethree();
        }
      if (!digitalRead(StartPin)){
       Tonetwo();
       gamestate = GameState :: IN_PROGRESS; // If the handle loses connection with start point the circuit is broken and the game starts
      }
      break;
    case GameState::IN_PROGRESS: 
      digitalWrite(GreenLed, HIGH);
      digitalWrite(RedLed, HIGH);
      if (digitalRead(Lid)){
        gamestate = GameState :: BEGIN; 
        }
      if (!digitalRead(EndPin)) {  // you succeeded
       //digitalWrite(RedLed, LOW);
       Toneone();
       gamestate = GameState :: END;   
      }
      else if (!digitalRead(FailPin)){
        //For an active buzzer
         //digitalWrite(Buzzer, HIGH);
         // turn the LED on (HIGH is the voltage level)
         //delay(1000);    
         //digitalWrite(Buzzer, LOW);
        tone(Buzzer, 100,1000);
        
        gamestate = GameState :: BEGIN; 
      }
      break;
       
        
    case GameState::END:
      digitalWrite(GreenLed, HIGH);
      digitalWrite(RedLed, LOW);
      if (oxo == 1){
        gamestate = GameState :: BEGIN; 
        break;
        }

      //if (!digitalRead(Lid)) {  
        //gamestate = GameState :: BEGIN; 
      //}
      break;
  }
}

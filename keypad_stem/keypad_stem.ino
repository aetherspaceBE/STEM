//www.elegoo.com
//2016.12.9

/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = { // R means reset button
  {'1','2','3','R'},
  {'4','5','6','R'},
  {'7','8','9','R'},
  {'R','0','R','R'} 
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
const byte codeLength = 4;
bool correctNumbers [codeLength];
char correctCode [codeLength] = {'2', '9', '2', '3'};
int currentNumber = 0;

byte red[codeLength] = {11, 12, 13, 14};
byte green[codeLength] = {15, 16, 17, 18};

const byte buzzer = 10;

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  for (int i=0; i<codeLength; i++) {
    pinMode(red[i], OUTPUT);
    pinMode(green[i], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void loop(){
  char key = customKeypad.getKey();
  if (key == 'R')
    reset_keypad();
  else if (key != NO_KEY) {

    if (currentNumber % codeLength == 0) {
      Serial.println("first number entered");
      reset_keypad();
    }
    
    // enteredCode += key; // add the key to the entered code
    correctNumbers[currentNumber] = (key == correctCode[currentNumber]);
    digitalWrite(red[currentNumber], HIGH);
    digitalWrite(green[currentNumber], HIGH);
    Serial.print("Entered number on position " + String(currentNumber) + ": ");
    Serial.println(key);
    currentNumber++;

    // check if the entered code matches the correct code
    if (currentNumber >= codeLength) {
      Serial.println("full code entered");
      bool correct = true;
      for (int i=0; i<codeLength; i++) {
        Serial.print("number " + String(i) + " is ");
        if (correctNumbers[i]) {
          digitalWrite(red[i], LOW);
          digitalWrite(green[i], HIGH);
          Serial.println("correct");
        }
        else {
          digitalWrite(red[i], HIGH);
          digitalWrite(green[i], LOW);
          correct = false;
          Serial.println("incorrect");
        }
      }
      // currentNumber = 0;
      if (correct) {
        Serial.println("entered code is correct");
        tone(buzzer,1000,500);
        delay(500);
      }
      else {
        tone(buzzer,500,300);
        delay(500);
        Serial.println("entered code is not correct");
      }
    }
  }
}

void reset_keypad() {
  currentNumber = 0;
  for (int i=0; i<codeLength; i++) {
    Serial.println("resetting");
    digitalWrite(red[i], LOW);
    digitalWrite(green[i], LOW);
    correctNumbers[i] = false;
  }
}

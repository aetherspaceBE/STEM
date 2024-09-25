/*tone generate.
  created by SriTu Tech team.
  Read the code below and use it for any of your creation
*/

#include "pitches.h"//tone library

void setup() {
  //Don't need setup function

}

void loop() {
  //Toneone();
  //delay(10000);
  
  //Tonetwo();
  //delay(10000);
  //Tonethree();
  //delay(10000);
  Tonefour();//uncomment this tone
  delay(10000);
}

void Toneone() {
  int melody[] = { //tone array
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0,
    NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_A3, NOTE_G3,
    NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_A3, NOTE_G3,
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_G3, 0
  };

  int noteDurations[] = {4, 8, 8, 4, 4, 4, 8, 8, 8, 8, 4, 4, 8, 8, 8, 8, 4, 4, 4, 8, 8, 4, 4};

  for (int thisNote = 0; thisNote < 23; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(10, melody[thisNote], noteDuration); //play tone
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);//delay
    noTone(10);//tone off
  }
}
void Tonetwo() {
  int melody2[] = {NOTE_GS7, NOTE_DS8, NOTE_GS7, 0, NOTE_DS8, NOTE_DS8, 0, NOTE_GS7, NOTE_GS7};

  int noteDurations[] = {4, 8, 8, 4, 8, 8, 4, 4, 4};

  for (int thisNote = 0; thisNote < 9; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(10, melody2[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(10);
  }

}
void Tonethree() {
  int melody3[] = {NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6, NOTE_C7,
                   NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7
                  };

  int noteDurations[] = {4, 8, 8, 4, 8, 8, 4, 4, 4};

  for (int thisNote = 0; thisNote < 9; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(10, melody3[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(10);
  }

}

void Tonefour() {
  int melody4[] = {  NOTE_F5, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_GS5,
                     NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_FS5, NOTE_F5, NOTE_C6,
                     NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_GS5, NOTE_AS5, NOTE_C6,
                     NOTE_AS5, NOTE_F5, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_C6,
                     NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_FS5, NOTE_DS5,
                     NOTE_F5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_FS5, NOTE_F5
                  };

  int noteDurations[] = {4, 8, 4, 8, 8, 8, 4, 4, 8, 8, 4, 8, 8, 4, 8, 4, 8, 8, 8, 4, 8, 8, 2, 4, 8, 4, 8, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 2};

  for (int thisNote = 0; thisNote < 7; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(10, melody4[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(10);
  }

}

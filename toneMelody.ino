/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"

#define PROG_NAME "******toneMelody******"     //Descriptive name of this software, 20 characters.
#define VERSION "Version: 0.1"     //Version of this firmware.
#define TONE_PIN 8
#define BAUDRATE 115200


void playMelodyArray() {
  // notes in the melody:
  int melody[6][8] = {
    {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4}, //Shave and a hair cut
    {NOTE_C5, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, 0, NOTE_B4, NOTE_C5},
    {NOTE_C6, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, 0, NOTE_B5, NOTE_C6},
    {NOTE_C7, NOTE_G6, NOTE_G6, NOTE_A6, NOTE_G6, 0, NOTE_B6, NOTE_C7},
    {NOTE_C8, NOTE_G7, NOTE_G7, NOTE_A7, NOTE_G7, 0, NOTE_B7, NOTE_C8},
    {NOTE_C6, NOTE_F7, NOTE_G7, NOTE_C6, NOTE_F7, NOTE_G7, NOTE_C6, NOTE_C6}  //C major cord notes
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
  };

  //Itterate over melodys
  for (int thisMelody = 0; thisMelody <6; thisMelody++){
    Serial.print("Playing melody number: ");
    Serial.println(thisMelody);    
  
  // iterate over the notes of the melody:
  //Play a melody
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(TONE_PIN, melody[thisMelody][thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;    
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(TONE_PIN);
  }// end play a melody
  int pauseBetweenMelody = 1000 / noteDurations[5] * 5;
   delay(pauseBetweenMelody);
  }//end thisMelody
}//playMelodyArray

void setup() {
  //Serial setup
  delay(100);
  Serial.begin(BAUDRATE);
  delay(100);                         //Wait before sending the first data to terminal
  Serial.println(F(PROG_NAME));
  Serial.println(F(VERSION));

  playMelodyArray();
  delay(1000);
}//end setup

void loop() {
  // no need to repeat the melody.
  //  playMelodyArray();
}

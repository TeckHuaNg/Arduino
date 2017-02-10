/*
        Title: 321Maker Experiment #008 - Buzzer
        Description: This program will turn on the buzzer when the SW1 button is pressed. 
        Tutorial:  http://321maker.com/e/buzzer
        Revision Date: January 15, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield
*/
#include "pitches.h";
int buzzerPin  = 5 ;  //The buzzerPin is connected to pin 5 of the Arduino.
int button1Pin = 2;   //The SW1 button is connect to pin 2 of the Arduino.

void setup() { //The Setup function runs once.
  pinMode(buzzerPin, OUTPUT);  //Setup red LED pin as an output pin.
  pinMode(button1Pin, INPUT);  //Setup button1 pin as an input pin.
}

void loop() { //The loop function runs forever.
  if (digitalRead(button1Pin) == LOW) { //Check to see if button1 is pressed.
               //Play a tone of 2000Hz for 50 milliseconds.
 
 tone(buzzerPin,2200); // then buzz by going high
    tone(buzzerPin,NOTE_B5,3000);
    delay(1000); 
    tone(buzzerPin,NOTE_A7,500);
    delay(1000); 
    tone(buzzerPin,NOTE_G4,200);
    delay(1000); 
    tone(buzzerPin,NOTE_A4,500);
    delay(1000);    // waiting
    
       // and waiting more
    tone(buzzerPin,NOTE_B4,2200); 
    delay(3000);
    tone(buzzerPin,NOTE_B4,1000);
    delay(1000);    // waiting

     // and waiting more
    tone(buzzerPin,NOTE_E4,100); 
    delay(2000);    // waiting
                                // and waiting more
    tone(buzzerPin,NOTE_C4,100); 
    delay(2000);    // waiting
   
        // and waiting more

 
  }
      
}

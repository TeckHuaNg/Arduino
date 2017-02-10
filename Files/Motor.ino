#include <Stepper.h>
 
int enA  = 10;  // Enable pin 1 on Motor Control Shield   
int enB  = 11;  // Enable pin 2 on Motor Control Shield   
int dirA = 12;  // Direction pin dirA on Motor Control Shield
int dirB = 13;  // Direction pin dirB on Motor Control Shield
 
 
const int stepsPerRevolution = 20;  // Change this to fit the number of steps per revolution
                                     // for your motor
 
// Initialize the stepper library on pins 12 and 13:
Stepper myStepper(stepsPerRevolution, dirA, dirB);            
 
 
void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
 
  // Enable power to the motor
  pinMode(enA, OUTPUT);
  digitalWrite (enA, HIGH);
 
  pinMode(enB, OUTPUT);
  digitalWrite (enB, HIGH);  
}
 
void loop() {
  // Step five revolutions into one direction:
  myStepper.step(stepsPerRevolution*5);
  delay(2000);
 
  // Step five revolutions in the other direction:
  myStepper.step(-stepsPerRevolution*5);
delay(2000);   
}

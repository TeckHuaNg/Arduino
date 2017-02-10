/*
  Example Bluetooth Serial Passthrough Sketch
 by: Jim Lindblom
 SparkFun Electronics
 date: February 26, 2013
 license: Public domain

 This example sketch converts an RN-42 bluetooth module to
 communicate at 9600 bps (from 115200), and passes any serial
 data between Serial Monitor and bluetooth module.
 AdaFruit Motor Shield library is used as reference in this project
 NewPing library is used to calculate the distance from ultrasonic sensors 
 */
#include<NewPing.h>
#include <SoftwareSerial.h>  
#include<AFMotor.h>
#define ECHO_PIN 16 // Echo Pin
#define TRIGGER_PIN 17 // Trigger Pin
#define MAX_DISTANCE 200


AF_DCMotor motor1(2);
AF_DCMotor motor2(4);


int bluetoothTx = 14;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 15;  // RX-I pin of bluetooth mate, Arduino D3
const int ledPin = 19;
const int ledPin2 = 18;
int ledState = LOW;
int ledState2 = LOW;
char data;
int data2;
int data3;
int data4;
unsigned long previousMillis = 0;
const long interval = 200;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup()
{
  Serial.begin(115200);  // Begin the serial monitor at 9600bps
  motor1.setSpeed(180);
  motor1.run(RELEASE);
  motor2.setSpeed(150);
  motor2.run(RELEASE);
  pinMode(18, OUTPUT);
  pinMode(19,OUTPUT);
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
}

void loop()
{
  if(bluetooth.available())  // If the bluetooth sent any characters
  {
    data=((char)bluetooth.read());
    Serial.println(data);
    // Send any characters the bluetooth receive and prints to the serial monitor  
    if(data == 'F'){
    // motor1 forward
    //motor2 off
    motor1.run(RELEASE);
    motor2.run(FORWARD);
  }else if(data == 'B'){
   motor1.run(RELEASE);
   motor2.run(BACKWARD);
  }else if(data == 'L'){
    motor1.run(FORWARD);
    motor2.run(RELEASE);
  }else if(data == 'R'){
    motor1.run(BACKWARD);
    motor2.run(RELEASE);
  }else if(data == 'G'){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }else if(data == 'H'){
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
  }else if(data == 'I'){
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
  }else if(data == 'J'){
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
  }else if(data == 'W'){
    data2 = 1;
  }else if(data == 'w'){
    data2 = 0;
  }else if(data == 'U'){
    data3 = 1;
  }else if(data == 'u'){
    data3 = 0;
  }else if(data == 'X'){
    data4 = 1;
  }else if(data == 'x'){
    data4 = 0;
  }else{
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
 }

 //Calculate the distance (in cm) based on the speed of sound.
 Serial.print(sonar.ping_cm());
 
//Blink
if(data2 == 1){
 unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
// set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}else if(data3 == 1){
 unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }
// set the LED with the ledState of the variable:
    digitalWrite(ledPin2, ledState2);
  }
  //open headlights
}else if(data4 == 1){
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin,HIGH);
}else{
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin,LOW);
}

//Stop if the distance to object is 20cm away
if(sonar.ping_cm() <= 40){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
 delay(10);
  // and loop forever and ever!
}


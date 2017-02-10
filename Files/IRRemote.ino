/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
int buzzerPin = 5;
int RECV_PIN = 6;
bool LEDStatus = false;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(13,HIGH);
  pinMode(12,HIGH);
  pinMode(11,HIGH);
  pinMode(10,HIGH);
  pinMode(9,HIGH);
  pinMode(buzzerPin,OUTPUT);
  //pinMode(8,HIGH);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    
    if(results.value == 0xFFB847){
      
    analogWrite(9,64);
    
    }
  
  if(results.value == 0xFF7887 ){
    analogWrite(9,128);
 }
 if(results.value == 0xE721C0DB ){
   analogWrite(9,255);}
 if(results.value == 0xFF04FB){
   analogWrite(10,64);}
 if(results.value == 0xFF847B){
   analogWrite(10,128);}
  if(results.value == 0xFF44BB){
   analogWrite(10,255);}
if(results.value == 0xFFC43B){
   analogWrite(11,64);}
   if(results.value == 0xFF24DB){
   analogWrite(11,128);}
   if(results.value == 0xFFA45B){
   analogWrite(11,255);}
if(results.value == 0xFFE41B){
   digitalWrite(9,LOW);
   digitalWrite(10,LOW);
   digitalWrite(11,LOW);}
if(results.value == 0xFFE817){
   digitalWrite(12,HIGH);}
   if(results.value == 0xFF58A7){
   digitalWrite(12,LOW);}
if(results.value == 0xFF18E7){
   digitalWrite(13,HIGH);}
   if(results.value == 0xFFD827){
   digitalWrite(13,LOW);}
if(results.value == 0xFF00FF){
   tone(buzzerPin,200);
   delay(500);
   tone(buzzerPin,100);
   }
    

    irrecv.resume(); // Receive the next value
  }   
  delay(100);
}

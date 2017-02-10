/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 6;
bool LEDStatus = false;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(13,HIGH);
  //pinMode(8,HIGH);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    
    if(results.value == 0x98CCF695){
      if (LEDStatus == false){
    digitalWrite(13,HIGH);
    LEDStatus = true;
    }else{
      digitalWrite(13,LOW);
      LEDStatus = false;
    }
    }
    irrecv.resume(); // Receive the next value
  }
  //if(result.value == ){
  //analogWirte(9,125);
 //}
 //if(result.value == ){
 //  analogWrite(9,10);}
  delay(100);
}

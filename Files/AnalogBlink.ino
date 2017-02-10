/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin1 = 9; // Analog output pin that the LED is attached to
const int analogOutPin2 = 10;
const int analogOutPin3 = 11;
const int analogOutPin4 = 12;
const int analogOutPin5 = 13;




int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(analogOutPin1, OUTPUT);
  pinMode(analogOutPin2, OUTPUT);
  pinMode(analogOutPin3, OUTPUT);
  pinMode(analogOutPin4, OUTPUT);
  pinMode(analogOutPin5, OUTPUT);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin1, outputValue);
  analogWrite(analogOutPin2, outputValue);
  analogWrite(analogOutPin3, outputValue);
  analogWrite(analogOutPin4, outputValue);
  analogWrite(analogOutPin5, outputValue);

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  delay(2);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  // read the value from the sensor:
  sensorValue = analogRead(analogInPin);
  // turn the ledPin on
  digitalWrite(analogOutPin1, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(analogOutPin1, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);

  //Display Green
digitalWrite(analogOutPin2, HIGH); //Turn on RED
delay(sensorValue);               //Wait for 2 seconds
digitalWrite(analogOutPin2, LOW);  //Turn off Red
delay(sensorValue);
//Display Blue
digitalWrite(analogOutPin3, HIGH); //Turn on RED
delay(sensorValue);               //Wait for 2 seconds
digitalWrite(analogOutPin3, LOW);  //Turn off Red
delay(sensorValue);
//Display  Magenta  (Red + Blue)
digitalWrite(analogOutPin1, HIGH); //Turn on RED
digitalWrite(analogOutPin2, HIGH); //Turn on RED
delay(sensorValue);               //Wait for 2 seconds
digitalWrite(analogOutPin1, LOW);  //Turn off Red
digitalWrite(analogOutPin2, LOW); //Turn on RED
delay(sensorValue);
//Display  Yellow  (Red + Green)
digitalWrite(analogOutPin1, HIGH); //Turn on RED
digitalWrite(analogOutPin3, HIGH); //Turn on RED
delay(sensorValue);               //Wait for 2 seconds
digitalWrite(analogOutPin1, LOW);  //Turn off Red
digitalWrite(analogOutPin3, LOW); //Turn of RED
delay(sensorValue);
//Display  Cyan  (Blue + Green) 
digitalWrite(analogOutPin2, HIGH); //Turn on BLUE
digitalWrite(analogOutPin3, HIGH); //Turn on GREEN
delay(sensorValue);               //Wait for 2 seconds
digitalWrite(analogOutPin2, LOW); //Turn of BLUE
digitalWrite(analogOutPin3, LOW);  //Turn off GREEN
delay(sensorValue);
//Display White  (Red + Blue + Green)
digitalWrite(analogOutPin1, HIGH); //Turn on RED
digitalWrite(analogOutPin2, HIGH); //Turn on BLUE
digitalWrite(analogOutPin3, HIGH); //Turn on GREEN
delay(sensorValue);               //Wait for 2 seconds
digitalWrite(analogOutPin1, LOW);  //Turn off RED
digitalWrite(analogOutPin2, LOW); //Turn off BLUE
digitalWrite(analogOutPin3, LOW); //Turn off GREEN
delay(sensorValue);

digitalWrite(analogOutPin4, HIGH); //Turn on RED
delay(sensorValue);               //Wait for 2 seconds
digitalWrite(analogOutPin4, LOW);  //Turn off Red
delay(sensorValue);
digitalWrite(analogOutPin5, HIGH); //Turn on RED
delay(sensorValue);               //Wait for 2 seconds
digitalWrite(analogOutPin5, LOW);  //Turn off Red
delay(sensorValue);
}

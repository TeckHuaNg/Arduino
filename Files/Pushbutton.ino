
int RGBRedPin  = 9 ;  //The red LED is connected pin 12 of the Arduino.
int RGBGreenPin = 10 ;//The blue LED is connected pin 13 of the Arduino.
int RGBBluePin = 11;
int button1Pin = 2;    //The SW1 button is connect to pin 2 of the Arduino.
    //The SW2 button is connect to pin 3 of the Arduino.

void setup() { //The Setup function runs once.
  pinMode(RGBRedPin, OUTPUT);  //Setup red LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT);  //Setup blue LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT);
  pinMode(button1Pin, INPUT);  //Setup button1 pin as an input pin.
    //Setup button2 pin as an input pin.
}

void loop() { //The loop function runs forever.
  Serial.println(digitalRead(button1Pin));//print out to screen, use bool to store data because 1/0 only
  delay(3);
  if (digitalRead(button1Pin) == LOW) { //Check to see if button1 is pressed.
    digitalWrite(RGBRedPin, HIGH);//Turn on the blue LED.
    delay(333);// delay light to turn off
    digitalWrite(RGBGreenPin, HIGH);
    delay(333);
    digitalWrite(RGBBluePin, HIGH);
    delay(333);
  } else {
    digitalWrite(RGBRedPin, LOW); //Turn off the blue LED.
    digitalWrite(RGBBluePin, LOW);
    digitalWrite(RGBGreenPin, LOW);
  }

  
}


int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int data = 0; //This will store the data from the sensor.
int redLedPin = 12;
int blueLedPin = 13;

void setup() { //The Setup function runs once.
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() { //The loop function runs forever.
  data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.
  Serial.print("Light value =");
  Serial.println(data);  //Print the data to the serial port.
  delay(500);           //Wait 1 second (1000mS) before running again.

if(analogRead(lightPin) < 500){
  // turn on red and blue
  digitalWrite(redLedPin, HIGH);


digitalWrite(blueLedPin, HIGH);



}else{
  //turn off red and blue
  
digitalWrite(redLedPin, LOW);

digitalWrite(blueLedPin, LOW);

}

}

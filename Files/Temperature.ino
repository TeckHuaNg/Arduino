

int tempPin = A2;     //The temperature sensor is plugged into pin A2 of the Arduino.
int data;             //This will store the data from the sensor.
int waitTime = 3000;  //Wait
void setup(void) {    //The Setup function runs once.
  Serial.begin(9600); //This will enable the Arduino to send data to the Serial monitor.
}

void loop(void) { //The loop function runs forever.
  data = analogRead(tempPin);        //Read from the temperature sensor
  Serial.print("Current temperature = "); //Serial.print displays to the Serial Monitor.
  Serial.print(data);                //This is the raw analog reading

  // Calculate and display temperature.
  float temperatureC = (5.0 * data * 100.0) / 1024;
  Serial.print(temperatureC); Serial.println(" degrees C");

  // Convert temperature to Fahrenheight and display.
  float temperatureF = (100 - temperatureC);
  Serial.print(temperatureF); Serial.println("degrees C temperautre away from boiling");

  delay(waitTime); //Wait waitTime before running again.
}

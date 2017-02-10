#include "DHT.h"
int DHT11Pin = 4;        //The DHT11 sensor  is connected to pin 4 of the Arduino. 
int waitTime = 1000;     //The amount of time to wait between sensor reads.
DHT dht(DHT11Pin, DHT11);//Initialize the sensor. 
int redLedPin = 12;
int blueLedPin = 13;
int RGBGreen = 10;
int RGBBlue = 11;
//DHT = object, dht is a name
void setup(){
  dht.begin();  //Start the sensor.
   pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
   pinMode(RGBBlue, OUTPUT);
  pinMode(RGBGreen, OUTPUT);
}

void loop()
{
  delay(waitTime);
  float humidity = dht.readHumidity();  //Read the humidity value from the sensor.
  float celsius = dht.readTemperature(); //Read the temperature (c) value from the sensor. 
  float fahrenheit = dht.readTemperature(true); //Read the temperature (f) value from the sensor.
  float heatIndexF = dht.computeHeatIndex(fahrenheit, humidity); //Calculate the heat index (f).
  float heatIndexC = dht.computeHeatIndex(celsius, humidity, false); //Calculate the heat index (c).

  Serial.print("Humidity   (%): "); 
  Serial.println(humidity );        //Display the humidity precentage.
  Serial.print("Temperature(c): ");
  Serial.println(celsius);          //Display the temperature in celsius.
  Serial.print("Heat index (c): ");
  Serial.println(heatIndexC);       //Display the heat index in celsius.
  Serial.print("Temperature(f): ");
  Serial.println(fahrenheit);       //Display the temperature in fahrenheit.
  Serial.print("Heat index (f): ");
  Serial.println(heatIndexF);       //Display the heat index in fahrenheit.
  Serial.print("Dewpoint:");
Serial.println(dewPoint(celsius,humidity));
if ( celsius>25){
  digitalWrite(redLedPin, HIGH);
  digitalWrite(blueLedPin,LOW);
}
else {
  digitalWrite(blueLedPin,HIGH);
  digitalWrite(redLedPin,LOW);
  }
if ( humidity<50){
digitalWrite(RGBGreen, HIGH);
digitalWrite(RGBBlue, LOW);
}
else {
digitalWrite(RGBBlue, HIGH);
digitalWrite(RGBGreen, LOW);
}  


}
  double dewPoint(double celsius, double humidity)
{
 double a = 17.271;
 double b = 237.7;
 double temp = (a * celsius) / (b + celsius) + log(humidity*0.01);
 double dP = (b * temp)/(a - temp);
 return dP;
}



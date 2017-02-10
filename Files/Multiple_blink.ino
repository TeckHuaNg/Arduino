/* Blink Multiple LEDs without Delay
*
* Turns on and off several light emitting diode(LED) connected to a digital
* pin, without using the delay() function.  This means that other code
* can run at the same time without being interrupted by the LED code.
*/
int led1 = 13;                // LED connected to digital pin 13
int led2 = 12;
int value1 = LOW;                // previous value of the LED
int value2 = LOW;                // previous value of the LED
long time1 = millis();
long time2 = millis();

long interval1 = 1000;           // interval at which to blink (milliseconds)
long interval2 = 500;

void setup()
{
pinMode(led1, OUTPUT);      // sets the digital pin as output
pinMode(led2, OUTPUT);
}

void loop()
{
unsigned long m = millis();

if (m - time1 > interval1){
   time1 = m;

   if (value1 == LOW)
     value1 = HIGH;
   else
     value1 = LOW;

   digitalWrite(led1, value1);
}

if (m - time2 > interval2){
   time2 = m;

   if (value2 == LOW)
     value2 = HIGH;
   else
     value2 = LOW;

   digitalWrite(led2, value2);
}
}

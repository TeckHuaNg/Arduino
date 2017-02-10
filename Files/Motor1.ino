#include<AFMotor.h>
int DCMotor1 = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DCMotor1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(DCMotor1, HIGH);
  
}

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potmtr = 1;
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  pos = analogRead(potmtr) * 0.175;
  
  myservo.write(pos);              
  delay(15);                     
  
}


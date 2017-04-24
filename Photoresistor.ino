#include <Servo.h>
Servo servo;

//PhotoResistor Pin
int lightPin = 0; //the analog pin the photoresistor is connected to
//the photoresistor is not calibrated to any units so this is simply a raw sensor value (relative light)

void setup()
{
  servo.attach(9);
  servo.write(0);
  delay(1000);
}

//LOOK AT KNOB EXAMPLE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 
void loop()
{
 int lightLevel = analogRead(lightPin); //Read the lightlevel 
 
 lightLevel = map(lightLevel, 0, 1023, 0, 180); 

 servo.write(lightLevel);
 
 delay(15);
}

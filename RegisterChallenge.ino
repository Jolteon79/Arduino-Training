/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
//THIS CODE IS BETTER THAN THE PROVIDED CODE

//  betterer one @ https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v32/experiment-14-using-a-shift-register
*/

int latchPin = 4;
int clockPin = 3;
int dataPin = 2;

byte leds = 0;

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  leds = 0;
  updateShiftRegister();
  delay(500);
  onThenOff();
  onThenOff();
  
  oneAtATime();
  oneAtATime();
  
  pairs();
  pairs();
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

//LED Patterns
//  1)all on, then all off
//  2)one on at a time
//  3)turn on & off outermost pair then work inward one pair at a time

void onThenOff()
{
    for (int i = 0; i < 8; i++)
    {
      bitSet(leds, i);
      bitWrite(leds,i,HIGH);
      updateShiftRegister();
      delay(250); 
    }
    for (int i = 7; i >= 0; i--)
    {
      bitSet(leds, i);
      bitWrite(leds,i,LOW);
      updateShiftRegister();
      delay(250); 
    }
}

void oneAtATime()
{
    for (int i = 0; i < 8; i++)
    {
      bitSet(leds, i);
      bitWrite(leds,i,HIGH);
      updateShiftRegister();
      delay(250); 
      bitWrite(leds,i,LOW);
      updateShiftRegister();
      delay(50); 
    }
}

void pairs()
{
    for(int i = 0; i < 4; i++)
    {
      bitSet(leds,i);
      bitWrite(leds,i,HIGH);
      bitSet(leds,7-i);
      bitWrite(leds,7-i,HIGH);
      updateShiftRegister();
      delay(250);
    }
    for(int i = 0; i < 4; i++)
    {
      bitSet(leds,i);
      bitWrite(leds,i,LOW);
      bitSet(leds,7-i);
      bitWrite(leds,7-i,LOW);
      updateShiftRegister();
      delay(250);
    }
}







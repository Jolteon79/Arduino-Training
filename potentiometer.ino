int sensorPin = 0;
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int sensorVal = 0;
//pots are 0 to 1023; 1023 / 8 is around 127

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 8; i++)
  {
    pinMode(ledPins[i],OUTPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal = analogRead(sensorPin);
  int split = sensorVal/127;
  
  for(int i = 0; i <= split; i++)
  {
    digitalWrite(ledPins[i],HIGH);
    //delay(sensorVal);
  }
  for(int j = split+1; j < 8; j++)
  {
    digitalWrite(ledPins[j],LOW);
    //delay(sensorVal);
  }
  
}

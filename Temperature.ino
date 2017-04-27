//TMP36 Pin Variables
int temperaturePin = 0; 

int red = 11;
int green = 10; 
int setting = 2;
int inc = 3;
int dec = 4;

boolean heat = true, limit = false;
int targetTemp;

void setup()
{
  Serial.begin(9600);
  Serial.println();
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(setting,INPUT);
  pinMode(inc,INPUT);
  pinMode(dec,INPUT);
  
  targetTemp = 72;
}
 
void loop()
{
 float temperature = getVoltage(temperaturePin);   
 temperature = (((temperature - .5) * 100)*1.8) + 32; 

 if(digitalRead(setting) == LOW)
 {
  if(heat)
    heat = false;
  else
    heat = true;
 }

 if(digitalRead(inc) == LOW)
  targetTemp += 1;
 if(digitalRead(dec) == LOW)
  targetTemp -= 1;
 

 Serial.print("Current Temperature: ");
 Serial.print(temperature);  
 Serial.println(" deg F"); 
 Serial.print("Target Temperature: ");
 Serial.print(targetTemp);
 Serial.println(" deg F"); 
 
 if(temperature < targetTemp-3 || (limit && heat))
 {
    heat = true;
    limit = true;
    Serial.println("--- OVERRIDE ---");
 }
 else if(temperature > targetTemp+3 || (limit && !heat))
 {
    heat = false;
    limit = true;
    Serial.println("--- OVERRIDE ---");
 }
 
 if( (temperature >= targetTemp && heat) || (temperature <= targetTemp && !heat) )
 {
    limit = false;
 }

 if(heat)
 {
    Serial.println("The unit is currently HEATING");
    digitalWrite(green,HIGH); 
    digitalWrite(red,LOW);
 }
 else
 {
    Serial.println("The unit is currently COOLING");
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
 }
 delay(1000); 
 Serial.println(); 

}

/*
 * getVoltage() - returns the voltage on the analog input defined by
 * pin
 */
float getVoltage(int pin)
{
 return (analogRead(pin) * .004882814); //converting from a 0 to 1023 digital range
                                        // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}

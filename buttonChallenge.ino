int bluePin = 13;
int redPin = 9;

int inPin1 = 2; 
int inPin2 = 3;
int inPin3 = 4;
int inPin4 = 5;
int count = 0;
boolean code[] = {false,false,false,false};
boolean answered[] = {false,false,false,false};

//piezo
int speakerPin = 10;
int notes[] = {1915, 1275, 956};

void setup() {
  // put your setup code here, to run once:
  pinMode(bluePin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(inPin1,INPUT);
  pinMode(inPin2,INPUT);
  pinMode(inPin3,INPUT);
  pinMode(inPin4,INPUT);
  pinMode(speakerPin,OUTPUT);
}

void loop() {
  
  //secret code: far left, far right, middle left, middle right
    for(int i = 0; i < 2; i++)
    {
      playTone(notes[1],300);
    }
  
  while(answered[0]==false || answered[1]==false || answered[2]==false || answered[3]==false )
  {
    if(digitalRead(inPin4) == LOW)
    {
      if(count == 0)
        code[3] = true;
      answered[3] = true;
    }
    if(digitalRead(inPin1) == LOW)
    {
      if(code[3])
        code[0] = true;
      answered[0] = true;
    }
    if(digitalRead(inPin3) == LOW)
    {
     if(code[0])
      code[2] = true;
     answered[2] = true;
    }
    if(digitalRead(inPin2) == LOW)
    {
      if(code[2])
        code[1] = true;
      answered[1] = true;
    }
  }
  
  if(code[3] && code[0] && code[2] && code[1])
  {
    digitalWrite(bluePin,HIGH);
    for(int i = 0; i < 3; i++)
    {
      playTone(notes[i],300);
    }
    delay(2000);
    digitalWrite(bluePin,LOW);
  }
  else
  {
    digitalWrite(redPin,HIGH);
    for(int i = 0; i < 3; i++)
    {
      playTone(notes[2-i],300);
    }
    delay(2000);
    digitalWrite(redPin,LOW);
  }

  for(int b = 0; b <= 3; b++)
    {
      code[b] = false;
      answered[b] = false;
    }
  
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

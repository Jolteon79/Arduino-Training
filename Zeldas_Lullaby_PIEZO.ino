/* Melody
 * (cleft) 2005 D. Cuartielles for K3
 *
 * This example uses a piezo speaker to play melodies.  It sends
 * a square wave of the appropriate frequency to the piezo, generating
 * the corresponding tone.
 *
 * The calculation of the tones is made following the mathematical
 * operation:
 *
 *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * where the different tones are described as in the table:
 *
 * note   frequency   period  timeHigh
 * c          261 Hz    3830       1915  
 * d          294 Hz    3400       1700  
 * e          329 Hz    3038       1519  
 * f          349 Hz    2864       1432  
 * g          392 Hz    2550       1275  
 * a          440 Hz    2272       1136  
 * b          493 Hz    2028       1014  
 * C          523 Hz    1912       956
 * D          587       1704       852
 * E          659       1517       759
 * F          698       1433       717
 * G          784       1276       638
 * A          880       1136       568
 * B          988       1012       506
 * 
 * high stuff
 * c -> w    1047        955       478
 * d -> q    1175        851       426
 * g -> s    1568        638       319
 *
 * http://www.arduino.cc/en/Tutorial/Melody
 
 music: bars 1-30 of http://herbalcell.com/static/sheets/legend-of-zelda-ocarina-of-time/zeldas-lullaby.pdf
 
 */
  
int speakerPin = 9;

int length = 58; // the number of notes
char notes[] = "bDagabDabDAGDCba bDagabDabDAGq qwBwBGwBABAEqwBwBGwsfaCbG"; // a space represents a rest
float beats[] = { 2,1,2,0.25,0.25,2,1,3,2,1,2,1,2,0.25,0.25,3,0.15, 
                  2,1,2,0.25,0.25,2,1,3,2,1,2,1,6,0.25,
                  2.5,0.15,0.15,0.15,0.15,2.5,2.5,0.15,0.15,0.15,0.15,2.5,2.5,0.15,0.15,0.15,0.15,1,1,4.5,
                  0.25,0.25,0.25,0.25,0.5};
int tempo = 250;

void playTone(int tone, float duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, float duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'w', 'q', 's'};
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956, 852, 759, 717, 638, 568, 506, 478, 426, 319 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 17; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    
    // pause between notes
    delay(tempo / 2); 
  }
}

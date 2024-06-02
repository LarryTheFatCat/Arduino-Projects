int speakerPin = 12;
int photocellPin = 0;
const int melody[] = {131, 0, 131, 147, 131, 175, 165, 131, 0, 131, 147, 131, 196, 175,
                      131, 0, 131, 262, 220, 175, 165, 147, 233, 0, 233, 220, 175, 196, 175, 0};
const int noteDurations[] = {4, 8, 4, 2, 2, 2, 1, 4, 8, 4, 2, 2, 2, 1, 
                            4, 8, 4, 2, 2, 2, 2, 2, 4, 8, 4, 2, 2, 2, 1, 10};

void setup() {
  // connect to port 9600, debugging purpose
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(photocellPin); // create readings
  Serial.println(reading); // print readings, debugging purpose
  if (reading > 300){ // based off line above, will det. if good else no.
    photoCellMusic(); // call function to run
  }
}

void photoCellMusic() {
  for (int thisNote = 0; thisNote < 30; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(speakerPin, melody[thisNote]);
    delay(noteDuration);
    delay(1.30);
    noTone(speakerPin);
 
    // Check the photocell sensor reading
    int sensorReadings = analogRead(photocellPin);
    while (sensorReadings < 300) {
      sensorReadings = analogRead(photocellPin);
      delay(100); // Adjust the delay as needed
    }
  }
}
  
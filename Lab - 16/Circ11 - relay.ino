const int DRIVE_PIN = 2;    // Transistor base connected to digital pin 2
bool positiveDirection = true;  // Initial direction is positive

void setup() {
  pinMode(DRIVE_PIN, OUTPUT);
}

void loop() {
  if (positiveDirection) {
    digitalWrite(DRIVE_PIN, HIGH); // Positive direction
  } else {
    digitalWrite(DRIVE_PIN, LOW);  // Negative direction
  }

  delay(1000);  // wait for a second

  positiveDirection = !positiveDirection;  // Switch direction for the next iteration
}
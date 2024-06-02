int LED = 9;
int fadeAmount = -5;
int brightness = 255;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  analogWrite(LED, brightness);

  brightness = brightness + fadeAmount;

  if(brightness == 0 || brightness == 255) {
    fadeAmount = fadeAmount * -1;
  }
  delay(50);
}
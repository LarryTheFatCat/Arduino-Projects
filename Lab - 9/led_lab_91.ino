// variables wont change, thus const
const int btnPin = 2; // btn pin
const int ledPins[] = {3,4,5,6}; // led variables 
const int numLed = 4; // # of leds

// changeable variables
int buttonState = 0; // init btn state set 0, will increase 
int lastButtonState = LOW; // prev reading
int ledState = 0;
bool ledOn = false; // sets the led to default false

void setup() {
  // connect to serial port
  Serial.begin(9600);
  for(int i=0;i<numLed;i++){
    pinMode(ledPins[i], OUTPUT);
  }
  
  pinMode(btnPin, INPUT_PULLUP);
}

// def function that will iterate throughout simulation
void loop() {
  buttonState = digitalRead(btnPin);
  
  if(buttonState == LOW && lastButtonState == HIGH) {
    // check if state equal to num led
    if(ledState == numLed) {
      turnLedOn();
    } else if(ledState > numLed) {
      turnLedOff();
    } else if(ledState < numLed) {
      turnEachLedOn();
    }
  } else if(buttonState == HIGH && lastButtonState == LOW) {
  }
  
  lastButtonState = buttonState;
}


void turnLedOn() {
  for(int i=0;i<numLed;i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  ledState++;
}

void turnLedOff() {
  for(int i =0;i<numLed;i++) {
    digitalWrite(ledPins[i], LOW);
  }
  ledState = 0;
}
void turnEachLedOn() { //function that turns LEDs on and off individually
  digitalWrite(ledPins[ledState], !digitalRead(ledPins[ledState]));
  ledOn = !ledOn; //updates LED state
  if (!ledOn) { //if LED is turned off, go to next LED
    ledState++;
  }
}
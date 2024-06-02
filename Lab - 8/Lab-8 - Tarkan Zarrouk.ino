  // constants won't change

  const int BUTTON = 10;

  // variables will change

  int lastState = HIGH;
  int currentState; // the current reading from the previous state

  void setup() {
    // init serial communication
    Serial.begin(9600);
    // init the push button 
    // The pull-up input pin will be HIGH wehn the switch is
    // open an LOW when the swtch is closed.
    pinMode(BUTTON, INPUT_PULLUP);
  }

  void loop() {
    // read the state of the switch/button
    currentState = digitalRead(BUTTON);

    if(lastState == LOW && currentState == HIGH)
      Serial.println("The state changed from LOW to HIGH");
    // save the last state 
    lastState = currentState;
  }
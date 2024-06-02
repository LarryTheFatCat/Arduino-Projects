#include <Servo.h>

// init servo obj
Servo myservo;

// set servo pin
int servoPin = 9;

// set init pos
int pos = 0;

// Self Timing Function
void setup() {
  pinMode(servoPin, OUTPUT); // set pinmode for servo
}

void loop() {
  int pulseTime = 900; // set pulse time to 2100 ms (2.1 Seconds)
  // int pulseTime = 1500; // set deg to 90
  // int pulseTie = 2100; // set deg to 180
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseTime); 
  digitalWrite(servoPin, LOW);
  delay(25);
}


/*
Code below makes servo go from 0 -> 180, rotating and rotating back
on endless loop - hence "loop()" function being used!
*/

/**void setup() {
  myservo.attach(9); // pin 9 setup
}


// consistent loop for servo
void loop() {
  for(pos=0;pos<180;pos++) {
    myservo.write(pos); // go based on value
    delay(15); // set 15 ms delay time
  }
  for(pos=180;pos>=180;pos--) {
    myservo.write(pos);
    delay(15);
  }
}
*/

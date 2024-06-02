// LED Pin Variables
int ledPins[] = {2,3,4,5,6,7,8,9};
				// An array to hold the 
				// pin each LED is connected to
				// i.e. LED #0 is connected to pin 2

void setup() {
  for(int i=0;i<8;i++) {
    pinMode(ledPins[i], OUTPUT);
    // we use this to set LED pins to output
  }
}

void loop() {
    // oneAfterAnotherNoLoop();
  
  // oneAfterAnotherLoop();
  
    // oneOnAtATime();
  
    inAndOut();
}

/*
* oneAnotherAnotherNoLoop() - will light oen then
* delay for delayTime then light the next LED it will
* turn them off
*/

void oneAfterAnotherNoLoop() {
  int delayTime = 100;
  	// the time (in ms) to pause
  	// between LEDs
  digitalWrite(ledPins[0], HIGH); // turns on LED Pin 0
  delay(delayTime);
  
  digitalWrite(ledPins[1], HIGH);
  delay(delayTime);
  
  digitalWrite(ledPins[2], HIGH);
  delay(delayTime);
  
  digitalWrite(ledPins[3], HIGH);
  delay(delayTime);
  
  digitalWrite(ledPins[4], HIGH);
  delay(delayTime);
  
  digitalWrite(ledPins[5], HIGH);
  delay(delayTime);  
  
  digitalWrite(ledPins[6], HIGH);
  delay(delayTime);
  
  digitalWrite(ledPins[7], HIGH);
  delay(delayTime);

  digitalWrite(ledPins[0], LOW);
  delay(delayTime);
  
  digitalWrite(ledPins[1], LOW);
  delay(delayTime);
 
  digitalWrite(ledPins[2], LOW);
  delay(delayTime);

  digitalWrite(ledPins[3], LOW);
  delay(delayTime);
  
  digitalWrite(ledPins[4], LOW);
  delay(delayTime);

  digitalWrite(ledPins[5], LOW);
  delay(delayTime);

  digitalWrite(ledPins[6], LOW);
  delay(delayTime);

  digitalWrite(ledPins[7], LOW);
  delay(delayTime);
}


/*
* Super boring method above, oneAfterAnotherLoop(); does that but easier
*/

void  oneAfterAnotherLoop(){
  int delayTime = 100;
  // use for loop to turn each on the off
  for(int i=0;i<=8;i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
  }
  /*
  * if we want to decrease it using for loops,
  * we can set the pin value to max, then decrement
  * by one each time??
  */
  for(int i=0;i<=8 ;i++) {
    digitalWrite(ledPins[i], LOW);
    delay(delayTime);
  }
}

void oneOnAtATime() {
  int delayTime = 100; // 100 ms
  /*
  * For this, we want to turn on one led, then turn off 
  * then turn the next... etc
  */
  for(int i=0; i<8;i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}



void inAndOut(){
  int delayTime = 100;  
                       
  int offLED1 = 2;      
  int offLED2 = 5;      

  for(int i = 3; i >= 0; i--) {
    int onLED2 = 7 - i; 
    
    digitalWrite(ledPins[offLED1], LOW); 
    digitalWrite(ledPins[offLED2], LOW); 
    digitalWrite(ledPins[i], HIGH);      
    digitalWrite(ledPins[onLED2], HIGH); 
    
    int offLED1 = i;
    int offLED2 = onLED2;
    
    delay(delayTime);
  }

  // runs the LEDs into the middle
  for(int i = 0; i <= 3; i++) {
    int onLED2 = 7 - i; // this is the second LED to go on ie. LED #7 when i = 0
    digitalWrite(ledPins[offLED1], LOW);
    digitalWrite(ledPins[offLED2], LOW);
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[onLED2], HIGH);
    offLED1 = i;
    offLED2 = onLED2;
    delay(delayTime);
  }
}

//The 74HC595 uses a cerial communication
//link which has three pins
int data = 2;
int clock = 3;
int latch = 4;

//Used for single LED manipulation
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;

void setup()
{
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
}

void loop() {
  int delayTime = 100; //the number of milliseconds to delay
                       //between LED updates
  for(int i =0; i<256;i++) {
    updateLEDs(i);
    delay(delayTime);
  }
  //for(int i = 0; i < 8; i++){
    //changeLED(i,ON);
    //delay(delayTime);
  //}
  //for(int i = 0; i < 8; i++){
    //changeLED(i,OFF);
    //delay(delayTime);
  //}
}

void updateLEDs(int value){
  digitalWrite(latch, LOW);    //Pulls the chips latch low
  shiftOut(data, clock, MSBFIRST, value); //Shifts out the 8 bits to the shift register
  digitalWrite(latch, HIGH);   //Pulls the latch high displaying the data
}

void updateLEDsLong(int value){
  digitalWrite(latch, LOW);      //Pulls the chips latch low
  for(int i = 0; i < 8; i++){    //Will repeat 8 times (once for each bit)
  int bit = value & B10000000;   //We use a "bitmask" to select only the eight
                                 //bit in our number (the one we are addressing this time through
  value = value << 1;            //we move out number up one bit value so nex time bit 7 value will be
                                 //bit 8 and we will do our math on it
  if(bit == 128){digitalWrite(data, HIGH);}   //if bit 8 is set then set our data pin high
  else{digitalWrite(data, LOW);}              //if bit 8 is unset then set our data pin low
  digitalWrite(clock, HIGH);                  //the next three lines pulse the clock pin
  delay(1);
  digitalWrite(clock, LOW);
  }
  digitalWrite(latch, HIGH);  //pulls the latch high shifting our data into being displayed
}


//These used in bitwise math to change individual LEDs
int bits[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
int masks[] = {B11111110, B11111101, B11111011, B11110111, B11101111, B11011111, B10111111, B01111111};

void changeLED(int led, int state){
  ledState = ledState & masks[led];  //clears ledState of the bit we are addressing
  if(state == ON){ledState = ledState | bits[led];} //if the bit is on we will add it to ledState
  updateLEDs(ledState);              //send the new LED state to the shift register
}

  
  
  
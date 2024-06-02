int redPin=8;
int greenPin=9;
int bluePin=10;

void setup() {
  // put your setup code here, to run once:
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
setColor(255,0,0); //sets to colour red
delay(500);
setColor(255,20,0); //sets to colour orange
delay(500);
setColor(255,255,0); //sets to colour yellow
delay(500);
setColor(0,255,0); //sets to colour green
delay(500);
setColor(0,0,255); //sets to colour blue
delay(500);
setColor(0,255,255); //sets to colour aqua
delay(500);
setColor(255,0,255); //sets to colour purple
delay(500);
}

void setColor(int red, int green, int blue) {
red = 255 - red;
green = 255 - green;
blue = 255 - blue;
analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);  
}


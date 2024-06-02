
#define ANALOGREFVOLTAGE 5.555
int temperaturePin = A0;
#define speakerPin 11


void setup() {
  // Start the Serial connection
  Serial.begin(9600);  
  pinMode(speakerPin, OUTPUT);
  pinMode(temperaturePin, INPUT);

}
 
void loop() {
 float temperature = 0;
 float temperatureC = 0;
 float temperatureK = 0;
 float temperatureF = 0;
 
 temperature = getVoltage(temperaturePin); 
 temperatureC = (temperature - .5) * 100; 
 temperatureK = ((temperature - .5) * 100) + 273.15; 
 temperatureF = (((temperature - .5) * 100) * 9/5) + 32;
 
if (temperatureC > 30) {
  digitalWrite(speakerPin, HIGH);
}

else {
  digitalWrite(speakerPin, LOW);
}

 Serial.println("°C:"+(String)temperatureC+"     °F:"+(String)temperatureF+"     °K:"+(String)temperatureK+"");

 delay(1000);                                     
}
 
float getVoltage(int pin) { 
  
  return(float(analogRead(pin))* float(ANALOGREFVOLTAGE/1023.000));  
}

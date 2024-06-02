int trigPin = 12;
int echoPin = 11;
int pingTravelTime;
float pingTravelDistance;
float distanceToTarget;
int dt = 50;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTravelTime = pulseIn(echoPin, HIGH);
  delay(25);
  pingTravelDistance = (pingTravelTime * 765. * 5280. * 12) / (3600. * 1000000);
  distanceToTarget = pingTravelDistance / 2;
  Serial.print("Distance to Target is: ");
  Serial.print(distanceToTarget);
  Serial.println(" in.");
  delay(dt);
}
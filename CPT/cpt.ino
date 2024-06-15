#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int weightMeasure = A1;
int servoPin = A3;
int pos = 0;
Servo servo;

int ir_pin = 10;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };

Keypad customKeyPad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
String passwordInput = "";
String password = "12345D";

void setup() {
  lockVault();
  servo.attach(servoPin,500, 2500);
  Serial.begin(250000);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.print("    Welcome        ");
  delay(500);
  lcd.clear();
  lcd.print("Enter Password: " + passwordInput);
  pinMode(ir_pin, INPUT);
}

void loop() {
  char customKey = customKeyPad.getKey();
  int pressureMass = analogRead(weightMeasure);
  int irRead = digitalRead(ir_pin);

  // Print IR sensor value for debugging
  Serial.println(irRead);


  if (irRead == 0) {
    lcd.clear();
    lcd.println("WARNING FULL");
    delay(2000);
    lcd.clear();
    return;
  } else {
    if (customKey) {
      lcd.clear();
      passwordInput += customKey;  // Append the pressed key to the passwordInput
      lcd.print("Enter Password:");
      lcd.clear();
      lcd.print(passwordInput);


      if (customKey == 'A') {
        lcd.clear();
        passwordInput = "";
      }
      if (customKey == 'B') {
        lcd.clear();
        lcd.print("Locked!");
        lockVault();
        delay(1000);
        lcd.clear();
        lcd.print("Enter Password: ");
        passwordInput = "";
      }
      if (customKey == 'C') {
        lcd.clear();
        String capacityPressure = String(pressureMass);
        lcd.print(capacityPressure + " out of 1023");
        if (pressureMass == 1023) {
          lcd.clear();
          lcd.print("Error, Mass Max");
        }
      }
      if (customKey == 'D') {
        if (passwordInput == password) {
          lcd.clear();
          lcd.print("Access Granted");
          delay(2000);
          lcd.clear();
          lcd.print("Welcome!");
          delay(2000);
          lcd.clear();
          unlockVault();
          passwordInput = "";
        } else {
          lcd.clear();
          lcd.print("Access Denied");
          delay(2000);
          lcd.clear();
          lcd.print("Enter Password:");
          passwordInput = "";
        }
      }
    }
  }
}

void lockVault() {
  return servo.write(55);
}

void unlockVault() {
  return servo.write(0);
}
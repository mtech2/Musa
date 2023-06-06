#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#define Password_Length 8
#define sensorPin A0
int red = 10;
int bazer = 11;
int signalPin = 13;
int signalPin1 = 12;
int reader;

char Data[Password_Length];
char Master[Password_Length] = "123A456";
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

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

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  pinMode(signalPin, OUTPUT);
  pinMode(signalPin1, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(bazer, OUTPUT);
  pinMode(sensorPin,INPUT);
  digitalWrite(signalPin1, HIGH);
  digitalWrite(red, LOW);
}

void loop() {
//  Serial.print("Enter Pasword");
//  Serial.println(readSensor());
reader=analogRead(sensorPin);
Serial.println(reader);
  delay(500);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  customKey = customKeypad.getKey();
  if (customKey == 'C') {
    lcd.clear();
    clearData();
  }


  if (customKey && customKey != 'C') {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }

  if (data_count == Password_Length - 1) {
    lcd.clear();

    if (!strcmp(Data, Master)) {
      lcd.print("Correct");
      digitalWrite(signalPin, HIGH);
      digitalWrite(signalPin1, LOW);
      digitalWrite(bazer, HIGH);
      delay(3000);
      digitalWrite(bazer, LOW);
      digitalWrite(signalPin, LOW);
      digitalWrite(signalPin1, HIGH);

    }
    

    else {
      lcd.print("Incorrect");
      digitalWrite(red, HIGH);
      digitalWrite(bazer, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
      digitalWrite(bazer, HIGH);
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
      digitalWrite(bazer, HIGH);
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
      digitalWrite(bazer, HIGH);
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
      digitalWrite(bazer, HIGH);
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
      digitalWrite(bazer, HIGH);
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
      digitalWrite(bazer, HIGH);
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
      digitalWrite(bazer, HIGH);
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
      digitalWrite(bazer, HIGH);
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
      digitalWrite(bazer, HIGH);
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
      digitalWrite(bazer, HIGH);
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
      digitalWrite(bazer, HIGH);
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(bazer, LOW);
      digitalWrite(red, LOW);
      delay(100);
    }

    lcd.clear();
    clearData();
  }
if (reader>=300){
      lcd.clear();
      digitalWrite(bazer, HIGH);
      lcd.print("emergncy");
    }
    else  {
      if(reader<=300) {
      lcd.clear();
      digitalWrite(bazer,LOW);
      
      }
    }
}

void clearData() {
  while (data_count != 0) {
    Data[data_count--] = 0;
  }
  return;
}

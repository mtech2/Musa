int red = 3;
int yellow = 4;
int green = 5;
int i;
int j;
int k;
#include <Servo.h>
Servo myservo;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);




void setup() {
  Serial.begin(9600);
  Serial.println("WELCOME TO CODE");
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.println("WELCOME TO CODE");
  delay(1000);
  lcd.clear();
  myservo.attach(9);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  lights();
  serv();
}


void lights() {
  Serial.println("IN RED LIGHT LOOP");
  lcd.setCursor(0, 0);
  lcd.println("IN RED LIGHT LOOP");
  for (i = 0; i <= 10; i += 1) {
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    delay(100);
    lcd.clear();
  }
  Serial.println("YELLOW LIGHT LOOP");
    lcd.setCursor(0, 0);
    lcd.println("YELLOW LIGHT LOOP");
  
  for (j = 0; j <= 10; j += 1) {
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
    delay(100);
    lcd.clear();
  }
  Serial.println("GREEN LIGHT LOOP");
  lcd.setCursor(0, 0);
  lcd.println("GREEN LIGHT LOOP");
  for (k = 0; k <= 10; k += 1) {
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    delay(100);
    lcd.clear();
  }
}
void serv(){
  Serial.println("SERVO 0-90");
  lcd.setCursor(0, 0);
  lcd.println("SERVO 0-90");
  for (i = 0; i <= 180; i += 1) {
    myservo.write(i);
    delay(5);
  }
  delay(1000);
  Serial.println("SERVO 0-180");
  lcd.setCursor(0, 0);
  lcd.println("SERVO 0-180");
  for (j = 90; j <= 180; j += 1) {
    myservo.write(j);
    delay(5);
  }
  delay(1000);
}

//   for (i = 0; i <= 180; i += 1) { // goes from 0 degrees to 180 degrees
//     // in steps of 1 degree
//     myservo.write(i);              // tell servo to go to position in variable 'pos'
//     delay(5);                       // waits 15 ms for the servo to reach the position
//   }
//   delay(3000);
//   for (i = 180; i >= 0; i -= 1) { // goes from 180 degrees to 0 degrees
//     myservo.write(i);              // tell servo to go to position in variable 'pos'
//     delay(15);                       // waits 15 ms for the servo to reach the position
//   }
//   delay(3000);
// }
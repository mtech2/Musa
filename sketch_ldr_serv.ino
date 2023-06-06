#define led 5
#define ldr A0
#include <Servo.h>
int ldrreader;
int ledreader;
int ldr_value;
int serv_value;
Servo myservo;


void setup() {
  Serial.begin(9600);
  Serial.println("Sensor Detacted");
  pinMode(ldr, INPUT);
  myservo.attach(7);
}

void loop() {
  ldrreader = analogRead(ldr);
  Serial.print("Analog value= ");
  Serial.print(ldrreader);
  ldr_value = map(ldrreader, 0, 1023, 0, 180);
  Serial.print(" , maped_value= ");
  bright(ldr_value);
  serv(ldr_value);
  Serial.print(ldr_value);
  Serial.println("%");
}

void bright(int i) {
  analogWrite(led, i);
}
void serv(int j) {
  myservo.write(j);
}
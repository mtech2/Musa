#define led 5
#define ir1 2
#define ir2 3
#define ldr A0
#include <Servo.h>
int ir1reader;
int ir2reader;
int ldrreader;
int ldr_value;
int ledreader;
Servo myservo;


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ldr, INPUT);

  // put your setup code here, to run once:
}

void loop() {
 
  ldrreader = analogRead(ldr);
  Serial.print("Analog value= ");
  Serial.print(ldrreader);
  ldr_value = map(ldrreader, 0, 1023, 0, 100);
  Serial.print(" , maped_value= ");
  bright(ldr_value / 2);
  Serial.print(ldr_value);
  Serial.println("%");

 // bright(200, 50);
  // ir1reader = digitalRead(ir1);
  // ir2reader = digitalRead(ir2);
  // ledreader = digitalRead(led);
  // Serial.print("ir sensor 1: ");
  // Serial.print(ir1reader);
  // Serial.print(" , ir sensor 2: ");
  // Serial.print(ir2reader);
  // Serial.print(" , ldr sensor: ");
  // Serial.print(ldrreader);
  // // Serial.println("");
  //  delay(1000);
  //  if (ir1reader==0){
  //    Serial.println("sensor1");
  //  }
  //  if (ir2reader==0){
  //    Serial.println("sensor2");
  //  }
  //  if(ir1reader==0 || ir2reader==0){
  //     bright(220,50);
  //  }


  // put your main code here, to run repeatedly:
}

void bright(int i) {
  analogWrite(led, i);
}
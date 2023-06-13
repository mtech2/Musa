int green = 8;
int red = 7;
int yellow = 10;
int ena1 = 11;
int ena2 = 12;
int fanspeed = 0;
int ena = 9;
int data;
//int received;


void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(ena1, OUTPUT);
  pinMode(ena2, OUTPUT);
  // digitalWrite(driver1, HIGH);
}

void loop() {
  while (Serial.available() > 0) {
    data = Serial.read();
    Serial.println(data);

    if (data == 'a') {
      digitalWrite(green, HIGH);
    }
    if (data == 'b') {
      digitalWrite(green, LOW);
    }
    if (data == 'c') {
      digitalWrite(red, HIGH);
    }
    if (data == 'd') {
      digitalWrite(red, LOW);
    }
    if (data == 'e') {
      digitalWrite(yellow, HIGH);
    }
    if (data == 'f') {
      digitalWrite(yellow, LOW);
    }

    if (data > '0' && data <= '9') {
//      fanspeed = (data );
//      Serial.println(fanspeed);
      //      analogWrite(ena, fanspeed);
      //      digitalWrite(ena1, HIGH);
    }
    //    if (data == '7') {
    //      digitalWrite(ena1, LOW);
    //
    //    }
    analogWrite(ena1, fanspeed);
  }
}

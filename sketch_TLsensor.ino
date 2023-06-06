int sensor = 2;
int reader;
int led = 3;
int led1 = 4;
int led2 = 5;
int led3 = 11;
int led4 = 12;
int led5 = 13;
int led6 = 6;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.println("welcome to your code");
  // put your setup code here, to run once:
}

void loop() {
  reader = digitalRead(sensor);
  if (reader == LOW) {
    Serial.println("Sensor Detected Object");
    delay(500);
    Serial.println("Side One: Red Light ON-Side Two: Green Light ON");
    digitalWrite(led, HIGH);
    digitalWrite(led5, HIGH);
    delay(2000);
    digitalWrite(led6, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    Serial.println("Side One: Orange Light ON-Side Two: Orange Light ON");
    digitalWrite(led1, HIGH);
    digitalWrite(led4, HIGH);
    delay(1000);
    digitalWrite(led6, HIGH);
    delay(500);
    digitalWrite(led6, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led4, LOW);
    Serial.println("Side One: Green Light ON-Side Two: Red Light ON");
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(2000);
    digitalWrite(led6, HIGH);
    delay(500);
    digitalWrite(led6, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    //enter the traffic ligth code here
  } else {
    //do nothing
  }
}
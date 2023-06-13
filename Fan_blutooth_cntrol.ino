
void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);

}
void loop() {
  byte brightness = 0;
  if (Serial.available() > 0)
  {
    brightness = Serial.read ();
    if (brightness > '0' && brightness <= '9') {
      brightness = 25 * (brightness - '0');
      Serial.println (brightness);
//      Serial.print();
      analogWrite(9, brightness);
    }
  }
}

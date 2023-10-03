#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(8000);
  digitalWrite(LED, LOW);0
  delay(5000);
}

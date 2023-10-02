#define LED 13

void setup(){
  pinMode(LED, OUTPUT);
}

void loop(){
  digitalWrite(LED, HIGH);
  delay(8000);
  digitalWrite(LED, LOW);
  delay(5000);s
}

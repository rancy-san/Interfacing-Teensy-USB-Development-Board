int ledPin3 = 3;
int ledPin5 = 5;
int ledPin6 = 6;

void setup() {
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
}

void loop() {
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin5, HIGH);
  delay(1000);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, HIGH);
  delay(1000);
  digitalWrite(ledPin6, LOW);
  digitalWrite(ledPin3, HIGH);
  delay(1000);
}

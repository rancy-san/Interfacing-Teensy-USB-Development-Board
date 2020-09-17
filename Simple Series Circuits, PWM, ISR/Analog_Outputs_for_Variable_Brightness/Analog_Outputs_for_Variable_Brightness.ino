int ledPin3 = 3;
int ledPin5 = 5;
int ledPin6 = 6;

void setup() {
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
}

void loop() {
  analogWrite(ledPin3, 10); // red
  analogWrite(ledPin5, 10); // blue
  analogWrite(ledPin6, 10); // green
  
}

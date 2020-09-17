int ledPin3 = 3;
int ledPin5 = 5;
int ledPin6 = 6;
int pushButton12 = 12;
boolean buttonState = false;
int buttonCount = 0;

void setup() {
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(pushButton12, INPUT);
}

void loop() {
  buttonState = digitalRead(pushButton12);
  if(buttonState) {
    delay(1000);
    if(buttonCount == 1) {
      analogWrite(ledPin6, 0); // green
      analogWrite(ledPin3, 10); // red
    }
    if(buttonCount == 2){
      analogWrite(ledPin3, 0); // red
      analogWrite(ledPin5, 10); // blue
    }
    if(buttonCount == 3) {
      analogWrite(ledPin5, 0); // blue
      analogWrite(ledPin6, 10); // green
      buttonCount = 0;
    }
    buttonCount++;
  } else if(buttonCount == 0) {
    analogWrite(ledPin6, 0);
    analogWrite(ledPin3, 10); // red
    delay(300);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin5, 10); // blue
    delay(300);
    analogWrite(ledPin5, 0);
    analogWrite(ledPin6, 10); // green
    delay(300);
  }
}

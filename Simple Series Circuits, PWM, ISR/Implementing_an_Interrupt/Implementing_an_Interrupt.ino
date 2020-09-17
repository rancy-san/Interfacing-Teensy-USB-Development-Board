int ledPin3 = 3;
int ledPin5 = 5;
int ledPin6 = 6;
int pushButton12 = 12;
boolean buttonState = false;
int buttonCount = 0;
int lightState3 = 10;
int lightState5 = 0;
int lightState6 = 0;

void setup() {
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(pushButton12, INPUT);
}

void loop() {
  buttonState = digitalRead(pushButton12);
  if(buttonState) {
      attachInterrupt(digitalPinToInterrupt(ledPin6), changeState, CHANGE);
      attachInterrupt(digitalPinToInterrupt(ledPin3), changeState, CHANGE);
      attachInterrupt(digitalPinToInterrupt(ledPin5), changeState, CHANGE);
  } else {
    analogWrite(ledPin6, lightState6); // green
    analogWrite(ledPin3, lightState3); // red
    analogWrite(ledPin5, lightState5); // blue
  }
}

void changeState() {
  int tempLightState = lightState3;
  lightState3 = lightState5;
  lightState5 = lightState6;
  lightState6 = tempLightState;
}

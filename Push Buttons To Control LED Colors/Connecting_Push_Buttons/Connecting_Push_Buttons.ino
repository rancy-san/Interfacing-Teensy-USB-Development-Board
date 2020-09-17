int ledPinCustomPullUp = 7;
int ledPinBuiltInPullUp = 8;

void setup()   {            
  pinMode(ledPinCustomPullUp, INPUT);
  pinMode(ledPinBuiltInPullUp, INPUT_PULLUP);
}

void loop()                     
{
  if (digitalRead(ledPinCustomPullUp) == HIGH) {
    Serial.println("Button is not pressed...");
  } else {
    Serial.println("Button pressed!!!");
  }
  delay(250);
}

int redPin = 20;
int greenPin = 21;
int bluePin = 23;

int ledPinCustomPullUp = 7;
int ledPinBuiltInPullUp = 8;

void setup()   {
  Serial.begin(38400);
  pinMode(ledPinCustomPullUp, INPUT);
  pinMode(ledPinBuiltInPullUp, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

int redIntensity = 0;
int mode = 0;

void loop()                     
{

  // set all 3 pins to the desired intensity
  analogWrite(redPin, redIntensity);
  if (mode == 0) {
    // in mode zero, fade from red to green
    analogWrite(greenPin, 255 - redIntensity);
    analogWrite(bluePin, 0);
    Serial.print("greenIntensity: ");
    Serial.println(255 - redIntensity);
  } else {
    // in mode one, fade from red to blue
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255 - redIntensity);
  }
  
  if (digitalRead(ledPinCustomPullUp) == LOW) {
    // use mode zero when the first button is pressed
    mode = 0;
    Serial.println("mode 0");
  }
  if (digitalRead(ledPinBuiltInPullUp) == LOW) {
    // use mode one when the first button is pressed
    mode = 1;
    Serial.println("mode 1");
  }
  
  // remain at this color, but not for very long
  delay(10);
  
  // increase the red
  redIntensity = redIntensity + 1;
  // since 255 is the maximum, set it back to 0
  // when it increments beyond 255
  if (redIntensity > 255) {
    redIntensity = 0;
  }
}

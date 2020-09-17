int dataPin = 14; // SER
int latchPin = 16; // RCLK
int clockPin = 15; // SRCLK

int binaryPosition[] = {1, 3, 7, 15, 31, 63, 127, 255};
int tDelay = 50;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  digitalWrite(latchPin, 0);
  digitalWrite(dataPin, 0);
  digitalWrite(clockPin, 0);
}

void loop() {
  
  for(int i = 0; i < 8; i++) {
    shiftOut(dataPin, clockPin, MSBFIRST, 0);
    shiftOut(dataPin, clockPin, MSBFIRST, binaryPosition[i]);
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
    delay(tDelay);
  }

    for(int i = 0; i < 8; i++) {
    shiftOut(dataPin, clockPin, MSBFIRST, binaryPosition[i]);
    shiftOut(dataPin, clockPin, MSBFIRST, 255);
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
    delay(tDelay);
  }
  
    for(int i = 7; i >= 0; i--) {
    shiftOut(dataPin, clockPin, MSBFIRST, binaryPosition[i]);
    shiftOut(dataPin, clockPin, MSBFIRST, 255);
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
    delay(tDelay);
  }
  
    for(int i = 7; i >= 0; i--) {
    shiftOut(dataPin, clockPin, MSBFIRST, 0);
    shiftOut(dataPin, clockPin, MSBFIRST, binaryPosition[i]);
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
    delay(tDelay);
   
  }
}

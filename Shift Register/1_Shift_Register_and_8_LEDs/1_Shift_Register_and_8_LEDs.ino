int dataPin = 14; // SER
int latchPin = 16; // RCLK
int clockPin = 15; // SRCLK

int leds = 1;
int tDelay = 500;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  digitalWrite(latchPin, 0);
  digitalWrite(dataPin, 0);
  digitalWrite(clockPin, 0);
}
 
void loop() 
{
  for (int i = 0; i < 7; i++)
  {
   shiftOut(dataPin, clockPin, MSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
   digitalWrite(latchPin, LOW);
   leds <<= 1;
   
   delay(tDelay);
  }

  for (int i = 7; i > 0; i--)
  {
   shiftOut(dataPin, clockPin, MSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
   digitalWrite(latchPin, LOW);
   leds >>= 1;
   
   delay(tDelay);
  }
}

int dataPin = 14; // SER
int latchPin = 15; // RCLK
int clockPin = 16; // SRCLK
int pbIn = 9 ;// button at pin 9; 

int tDelay = 250; // debounce method
int i = 0; // counter for 7SegDisplay
int j = 0; // counter for 7SegDisplay
int k = 0; // counter reset LED
int buttonPressCounter = 0;
boolean state = LOW; // button state is not pushed
boolean heldState = LOW; // button state is not held

// hold display values in array
byte sevenSegmentDisplay[10] = {
  // byte code order for 7seg... 
  // ... a b c d e f g (DEC)
  
  B11111111, // everything off
  B01111111, // A
  B10111111, // B
  B11011111, // C
  B11101111, // D
  B11110111, // E
  B11111011, // F
  B11111101, // G
  B11111110, // .
  B00000000 // 8.
};

void setup() 
{
  pinMode(pbIn,INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  digitalWrite(latchPin, LOW);
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
}

void loop() {
  
  state = digitalRead(pbIn);
  if(state == HIGH && heldState == LOW) { 
    heldState = HIGH;
    
    delay(tDelay); // debounce

    // display message below
    if(buttonPressCounter >= 11) {
      buttonPressCounter = 1;
    }
    if(buttonPressCounter > 0) {
      Serial.print("PBS press # ");
      Serial.print(buttonPressCounter);
    }

    switch(buttonPressCounter) {
      case 1: {
        Serial.print(" => Segment A");
        break;
      }
      case 2: {
        Serial.print(" => Segment B");
        break;
      }
      case 3: {
        Serial.print(" => Segment C");
        break;
      }
      case 4: {
        Serial.print(" => Segment D");
        break;
      }
      case 5: {
        Serial.print(" => Segment E");
        break;
      }
      case 6: {
        Serial.print(" => Segment F");
        break;
      }
      case 7: {
        Serial.print(" => Segment G");
        break;
      }
      case 8: {
        Serial.print(" => Segment Decimal Point");
        break;
      }
      case 9: {
        Serial.print(" => 8.");
        break;
      }
      case 10: {
        Serial.print(" => all segments OFF");
        break;
      }
    }
    
    Serial.print("\n");
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, sevenSegmentDisplay[i]); // shift held value
    shiftOut(dataPin, clockPin, LSBFIRST, sevenSegmentDisplay[j]); // shift next value
    digitalWrite(latchPin, HIGH);
    
    // segment display counter up by one
    j = j + 1;
    if(j > 9) {
      i++;
      j = 0;
    }
    // counter for counter display
    buttonPressCounter++;
  } else if(state == LOW && heldState == HIGH) {
    heldState = LOW;
  }
  
}

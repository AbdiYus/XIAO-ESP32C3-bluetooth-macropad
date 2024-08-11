#include "functions.h"

Encoder en(input_a, input_b); /*   Rotary encoder    */ 
volatile long position = -999;
volatile int direction = 1; 

/**
*   initKeypad() sets the pins for the keypad matrix, and
*   the library Keyboard.
*/
void functions::initKeyPad() {
    pinMode(row_1, INPUT);
    pinMode(row_2, INPUT);
    pinMode(col_1, OUTPUT);
    pinMode(col_2, OUTPUT);
    pinMode(encoder_pin, OUTPUT);
    Keyboard.begin();
    Serial.println("Connecting...");
    // screen::init();

    // set everything to low
    digitalWrite(col_1, LOW);
    digitalWrite(col_2, LOW);
    digitalWrite(encoder_pin, LOW);

    // screen::display();
}

/**
*   checkKeyPad() checks the keypad matrix for a key press.
*
*   @param int col - the column to check
*/
void functions::checkKeyPad(int col) {
  unsigned long timeNow; // time now
  unsigned long waitPeriod = 50; // wait period per press (in ms)
    digitalWrite(col, HIGH);
    functions::findKey();

    if(millis() >= timeNow + waitPeriod) { // wait period per press
        timeNow += waitPeriod;
        digitalWrite(col, LOW);
    }
}

/**
*   findKey() finds the key pressed on the keypad matrix. (position) 
*/
void functions::findKey() {
    if(!keyStroke::connected()) {
      Serial.println("not connected...");
      delay(1000);
      return;
    }

    int inputRow_1 = 0; // row reading (first row)
    int lastRowState_1 = 0; // last row reading (first row)

    int inputRow_2 = 0; // row reading (secound row)
    int lastRowState_2 = 0; // last row state (secound row)

    int encoderInput = 0;
    int lastEncoderInput = 0;

    inputRow_1 = digitalRead(row_1);
    inputRow_2 = digitalRead(row_2);

    if(inputRow_1) {
        if(digitalRead(col_1) == HIGH)   keyStroke::copy();
        if(digitalRead(col_2) == HIGH)  keyStroke::paste();

        lastRowState_1 = inputRow_1;
        while(inputRow_1 == lastRowState_1) inputRow_1 = digitalRead(row_1);
    }

    if(inputRow_2) {
        if(digitalRead(col_1) == HIGH)  keyStroke::screenShot();
        if(digitalRead(col_2) == HIGH)  keyStroke::altTab();

        lastRowState_2 = inputRow_2;
        while(inputRow_2 == lastRowState_2) inputRow_2 = digitalRead(row_2);
    }
}

signed char functions::mapEncoder(long val, long min, long max) {
    long output = map(val, min, max, -128, 127);
    output = constrain(output, -1, 1);
    return static_cast<signed char>(output);
}

void functions::scroll() {
    long val;   int result, currentDir; 
    if(!keyStroke::connected()) {
      Serial.println("not connected...");
      delay(1000);
      return; 
    }

    /*   Error handling if the value is a ASCII   */
    if(Serial.available())  en.write(0);

    /*   Sending direction value of the encoder   */
    val = en.read();
    if(val != position) {
      
      currentDir = (val - position) > 0 ? 1 : -1;
      // Serial.print("Val: "); Serial.print(val); 
      // Serial.print(" position: "); Serial.println(position); // Debug message 
      if(currentDir != direction) {
        if(currentDir == 1) en.write(11); // offset number for encoder 
        else en.write(-3);
      }

      Mouse.move(0, 0, mapEncoder(position, -999, 999));
      position = val;
      direction = currentDir; 
    }
}
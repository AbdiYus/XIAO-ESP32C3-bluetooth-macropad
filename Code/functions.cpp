#include "functions.h"

/**
*   initKeypad() sets the pins for the keypad matrix, and
*   the library Keyboard.
*/
void functions::initKeyPad() {
    pinMode(row_1, INPUT);
    pinMode(row_2, INPUT);
    pinMode(col_1, OUTPUT);
    pinMode(col_2, OUTPUT);
    Keyboard.begin();

    // set everything to low
    digitalWrite(col_1, LOW);
    digitalWrite(col_2, LOW);
}

/**
*   checkKeyPad() checks the keypad matrix for a key press.
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
    int inputRow_1 = 0; // row reading (first row)
    int lastRowState_1 = 0; // last row reading (first row)

    int inputRow_2 = 0; // row reading (secound row)
    int lastRowState_2 = 0; // last row state (secound row)

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
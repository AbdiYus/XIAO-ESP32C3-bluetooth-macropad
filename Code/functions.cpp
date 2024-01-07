#include "functions.h"

void functions::initKeyPad() {
    pinMode(row_1, INPUT);
    pinMode(row_2, INPUT);
    pinMode(col_1, OUTPUT);
    pinMode(col_2, OUTPUT);

    Serial.begin(9600);
    Keyboard.begin();

    // set everything to low
    digitalWrite(col_1, LOW);
    digitalWrite(col_2, LOW);
}

void functions::readInput() {
    inputRow_1 = digitalRead(row_1);
    inputRow_2 = digitalRead(row_2);
}

void functions::checkKeyPad(int col) {
    digitalWrite(col, HIGH);
    functions::findKey();

    if(millis() >= timeNow + waitPeriod) {
        timeNow += waitPeriod;
        digitalWrite(col, LOW);
    }
}

void functions::findKey() {
    if(inputRow_1) {
        if(digitalRead(col_1) == HIGH)   copy();
        if(digitalRead(col_2) == HIGH)  paste();

        lastRowState_1 = inputRow_1;
        while(inputRow_1 == lastRowState_1) inputRow_1 = digitalRead(row_1);
    }

    if(inputRow_2) {
        if(digitalRead(col_1) == HIGH)   screenShot();
        if(digitalRead(col_2) == HIGH)  altTab();

        lastRowState_2 = inputRow_2;
        while(inputRow_2 == lastRowState_2) inputRow_2 = digitalRead(row_2);
    }
}
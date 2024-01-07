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

void functions::checkKeyPad() {
    
}
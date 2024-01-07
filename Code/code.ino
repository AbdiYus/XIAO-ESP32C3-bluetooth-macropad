#include "functions.h"
#include "keystroke.h"

void setup() {
    functions::initKeyPad();
}

void loop() {
    functions::readInput();
    if(digitalRead(col_2) == LOW)   functions::checkKeyPad(col_1);
    if(digitalRead(col_1) == LOW)   functions::checkKeyPad(col_2);
}
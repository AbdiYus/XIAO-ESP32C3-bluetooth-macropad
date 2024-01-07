#include "functions.h"

void setup() {
    functions::initKeyPad();
}

void loop() {
    if(digitalRead(col_2) == LOW)   functions::checkKeyPad(col_1);
    if(digitalRead(col_1) == LOW)   functions::checkKeyPad(col_2);
}
/**
*   This is the main file for the project. It contains the setup and 
*   loop functions for the ESP32 keypad.
*
*   @file code.ino
*   @author Abdirahman Ahmed Yusuf
*/
#include "functions.h"

void setup() {
    functions::initKeyPad();
}

void loop() {
    if(digitalRead(col_2) == LOW)   functions::checkKeyPad(col_1);
    if(digitalRead(col_1) == LOW)   functions::checkKeyPad(col_2);
}
/**
*   This is the main file for the project. It contains the setup and 
*   loop functions for the xiao esp32c3 macropad.
*
*   @file code.ino
*   @author Abdirahman Ahmed Yusuf
*/
#include "functions.h"

void setup() {
  functions::initKeyPad();
  Serial.begin(115200);
}

void loop() {
  // if(digitalRead(col_2) == LOW)   functions::checkKeyPad(col_1);
  // if(digitalRead(col_1) == LOW)   functions::checkKeyPad(col_2);
  functions::checkKeyPad(col_1);
  functions::checkKeyPad(col_2);
  functions::scroll();
}
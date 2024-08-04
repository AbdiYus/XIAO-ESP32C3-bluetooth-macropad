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
  Serial.begin(115200);
  Serial.println("Starting now!");
}

void loop() {
  if(digitalRead(col_2) == LOW)   functions::checkKeyPad(col_1);
  if(digitalRead(col_1) == LOW)   functions::checkKeyPad(col_2);
  functions::scroll();
  
}
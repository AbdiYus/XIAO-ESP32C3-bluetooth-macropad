#include "functions.h"

Encoder en(input_a, input_b); /*   Rotary encoder    */
volatile long position = -999;
volatile int direction = 1;
bool wasCon = false;
bool isAnythingPressed = false; 
int timeNow = 50; 


/**
*   initKeypad() sets the pins for the keypad matrix, and
*   the library Keyboard.
*/
void functions::initKeyPad() {
  pinMode(row_1, INPUT);
  pinMode(row_2, INPUT);
  pinMode(col_1, OUTPUT);
  pinMode(col_2, OUTPUT);

  /*  Libraries  */
  Keyboard.begin();
  screen::init();

  // set everything to low
  digitalWrite(col_1, LOW);
  digitalWrite(col_2, LOW);

  screen::show(keyStroke::connected);
}

/**
*   checkKeyPad() checks the keypad matrix for a key press.
*
*   @param int col - the column to check
*/
void functions::checkKeyPad(int col) { /* TODO ADD BOOL AND SLEEP FUNCTION!!!!!*/
  /*  connection update  */
  if(!keyStroke::connected() || (keyStroke::connected() && wasCon)) {
    wasCon = keyStroke::connected() ? false : true;
    screen::show(keyStroke::connected());
    return;
  }

  digitalWrite(col, HIGH);
  functions::findKey();
  if(millis() - timeNow >= 100) {
    timeNow = millis(); 
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

  if((inputRow_1) && (inputRow_2)) {
    screen::changeMode();
    while((inputRow_1) && (inputRow_2)) {
      inputRow_1 = digitalRead(row_1);
      inputRow_2 = digitalRead(row_2);
    }
    return;
  }

  if(inputRow_1) {
    if(digitalRead(col_1) == HIGH) {
      screen::show(true, 4);  isAnythingPressed = true;
      mode == 1 ? keyStroke::paste() : keyStroke::explorer();
    }
    if(digitalRead(col_2) == HIGH) {
      screen::show(true, 3);  isAnythingPressed = true;
      mode == 1 ? keyStroke::copy() : keyStroke::terminal();
    }

    lastRowState_1 = inputRow_1;
    while(inputRow_1 == lastRowState_1) inputRow_1 = digitalRead(row_1);
    screen::show(true);
  }

  if(inputRow_2) {
    if(digitalRead(col_1) == HIGH) {
      screen::show(true, 2);  isAnythingPressed = true;
      mode == 1 ? keyStroke::screenShot() : keyStroke::undo();
    }
    if(digitalRead(col_2) == HIGH) {
      screen::show(true, 1);  isAnythingPressed = true;
      mode == 1 ? keyStroke::altTab() : keyStroke::comment();
    }

    lastRowState_2 = inputRow_2;
    while(inputRow_2 == lastRowState_2) inputRow_2 = digitalRead(row_2);
    screen::show(true);
  }
}

signed char functions::mapEncoder(long val, long min, long max) {
  long output = map(val, min, max, -128, 127);
  output = constrain(output, -1, 1);
  return static_cast<signed char>(output);
}

void functions::scroll() {
  if(!keyStroke::connected()) return;
  long val;   int result, currentDir;
  /*   Error handling if the value is a ASCII   */
  if(Serial.available())  en.write(0);

  /*   Sending direction value of the encoder   */
  val = en.read();
  if(val != position) {
    currentDir = (val - position) > 0 ? 1 : -1;
    if(currentDir != direction) {
      isAnythingPressed = true;
      if(currentDir == 1) en.write(11); // offset number for encoder
      else en.write(-3);
    }
    Mouse.move(0, 0, mapEncoder(position, -999, 999));
    position = val;
    direction = currentDir;
  }
}
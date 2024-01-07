#include "keystroke.h"
#include "functions.h"

int inputRow_1 = 0; // row reading (first row)
int lastRowState_1 = 0; // last row reading (first row)

int inputRow_2 = 0; // row reading (secound row)
int lastRowState_2 = 0; // last row state (secound row)

unsigned long timeNow = 0; // time now
unsigned long waitPeriod = 50; // wait period per press (in ms)

void setup() {
    functions::initKeyPad();
}

void loop() {

}
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Arduino.h>
#include <Keyboard.h>
#include "pins.h"

namespace functions {
    unsigned long timeNow = 0; // time now
    unsigned long waitPeriod = 50; // wait period per press (in ms)

    int inputRow_1 = 0; // row reading (first row)
    int lastRowState_1 = 0; // last row reading (first row)

    int inputRow_2 = 0; // row reading (secound row)
    int lastRowState_2 = 0; // last row state (secound row)
    
    void initKeyPad();
    void readInput();
    void checkKeyPad(int col);
    void findKey();
}

#endif
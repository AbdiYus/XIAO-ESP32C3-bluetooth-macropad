#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Arduino.h>
#include <Keyboard.h>
#include "pins.h"
#include "keystroke.h"

namespace functions {
    unsigned long timeNow = 0; // time now
    unsigned long waitPeriod = 50; // wait period per press (in ms)

    extern int inputRow_1; // row reading (first row)
    extern int lastRowState_1; // last row reading (first row)

    extern int inputRow_2; // row reading (secound row)
    extern int lastRowState_2; // last row state (secound row)
    
    void initKeyPad();
    void readInput();
    void checkKeyPad(int col);
    void findKey();
}

#endif
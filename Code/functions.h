/**
*   This file contains the functions for the ESP32 keypad.
*
*   @file functions.h
*   @author Abdirahman Ahmed Yusuf
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "pins.h"
#include "keystroke.h"

namespace functions {
    void initKeyPad();
    void checkKeyPad(int col);
    void findKey();
}

#endif
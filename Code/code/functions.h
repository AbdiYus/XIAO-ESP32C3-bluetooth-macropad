/**
*   This file contains the functions for the ESP32 keypad.
*
*   @file functions.h
*   @author Abdirahman Ahmed Yusuf
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*  Keyboard  */
#include "pins.h"
#include "keystroke.h"


/*  Encoder  */
#include <BleMouse.h>
#include "Encoder.h"

/*  Screen  */
#include "screen.h"

extern Encoder en;
extern volatile long position;
extern volatile int direction;  
extern bool wasCon; 
extern bool isAnythingPressed; 
extern int timeNow;

namespace functions {
    void initKeyPad();
    void checkKeyPad(int col);
    void findKey();
    signed char mapEncoder(long val, long min, long max);
    void scroll();
}

#endif
/**
*   This file contains the keystroke functions to the keypad.
*
*   @file keystroke.h
*   @author Abdirahman Ahmed Yusuf
*/
#ifndef KEYSTROKE_H
#define KEYSTROKE_H

#include <BleKeyboard.h>

namespace keyStroke {
    bool connected();
    void copy();
    void paste();
    void screenShot();
    void altTab();
}
#endif
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
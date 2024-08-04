#include "keystroke.h"

void keyStroke::copy() {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    Keyboard.releaseAll();
}

void keyStroke::paste() {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    Keyboard.releaseAll();
}

void keyStroke::screenShot() {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('s');
    Keyboard.releaseAll();
}

void keyStroke::altTab() {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_TAB);
    Keyboard.releaseAll();
}
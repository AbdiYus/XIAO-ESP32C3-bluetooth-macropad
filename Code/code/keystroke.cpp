#include "keystroke.h"

// bleDevice
bool keyStroke::connected() {
  return bleDevice.isConnected() ? true : false;  
}

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

void keyStroke::terminal() {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('j');
    Keyboard.releaseAll();
}

void keyStroke::comment() {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('k');
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    Keyboard.releaseAll();
}

void keyStroke::undo() {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('z');
    Keyboard.releaseAll();
}

void keyStroke::explorer() {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('b');
    Keyboard.releaseAll();
}
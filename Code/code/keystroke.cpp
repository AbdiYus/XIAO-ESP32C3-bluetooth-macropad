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
    delay(100);
    Keyboard.releaseAll();
}

void keyStroke::altTab() {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_TAB);
    Keyboard.releaseAll();
}
/**
*   Controls the screen of the keyboard   
*
*   @file screen.h
*   @author Abdirahman Ahmed Yusuf
*/
#ifndef SCREEN_H
#define SCREEN_H

#include <U8g2lib.h>
#include "pins.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;
extern volatile int lastButtonState; 
extern volatile int buttonState; 
extern volatile unsigned long lastDebounceTime; 
extern unsigned long debounceDelay; 

namespace screen {
  void init();
  void changeMode(); 
  void update();

  /* Graphics */
  void show(bool isCon, int pos = 0);
  void prepare();
}

#endif 
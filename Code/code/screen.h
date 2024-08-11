/**
*   Controls the screen of the keyboard   
*
*   @file screen.h
*   @author Abdirahman Ahmed Yusuf
*/
#ifndef SCREEN_H
#define SCREEN_H

// #include "ssd1306.h"
// #include "nano_gfx.h"
// #include "sova.h"

namespace screen {
  void init();
  void display();
  void changeMode(); 
  void update();
}

#endif 
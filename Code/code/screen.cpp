#include "screen.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
int mode = 1; 

void screen::init() {
  u8g2.begin();
}

void screen::prepare() {
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(3);
}

void screen::show(bool isCon, int pos) {
  u8g2.clearBuffer();
  prepare();

  /*  Modes  */
  drawMode(mode);

  mode == 1 ? u8g2.drawStr(74, 56, "Tab") : u8g2.drawStr(74, 56, "");
  mode == 1 ? u8g2.drawStr(64, 56, "alt") : u8g2.drawStr(70, 56, "/*/");
  mode == 1 ? u8g2.drawStr(70, 22, "SS") : u8g2.drawStr(70, 26, "Undo");
  mode == 1 ? u8g2.drawStr(104, 60, "Copy") : u8g2.drawStr(104, 58, "Term");
  mode == 1 ? u8g2.drawStr(104, 22, "PT") : u8g2.drawStr(104, 24, "exp");

  /*  Squares  */
  switch(pos) {
  case 1:  
    u8g2.drawRFrame(90, 2, 34, 32, 3); // bottom left
    u8g2.drawRFrame(90, 32, 34, 32, 3); // bottom right
    u8g2.drawRFrame(56, 2, 34, 32, 3); // top left
    u8g2.drawRBox(56, 32, 34, 32, 3);
    break;
  case 2: 
    u8g2.drawRBox(56, 2, 34, 32, 3);
    u8g2.drawRFrame(90, 32, 34, 32, 3); // bottom right
    u8g2.drawRFrame(90, 2, 34, 32, 3); // bottom left
    u8g2.drawRFrame(56, 32, 34, 32, 3); // top right
    break;
  case 3: 
    u8g2.drawRFrame(90, 2, 34, 32, 3); // bottom left
    u8g2.drawRBox(90, 32, 34, 32, 3); 
    u8g2.drawRFrame(56, 2, 34, 32, 3); // top left
    u8g2.drawRFrame(56, 32, 34, 32, 3); // top right
    break;
  case 4: 
    u8g2.drawRFrame(90, 32, 34, 32, 3); // bottom right
    u8g2.drawRFrame(56, 2, 34, 32, 3); // top left
    u8g2.drawRFrame(56, 32, 34, 32, 3); // top right
    u8g2.drawRBox(90, 2, 34, 32, 3);
    break;
  default: 
    u8g2.drawRFrame(90, 2, 34, 32, 3); // bottom left
    u8g2.drawRFrame(90, 32, 34, 32, 3); // bottom right
    u8g2.drawRFrame(56, 2, 34, 32, 3); // top left
    u8g2.drawRFrame(56, 32, 34, 32, 3); // top right
    break;
  }

  /*  Header  */
  u8g2.drawStr(7, 60, "C3_pad");
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  isCon == true ? u8g2.drawUTF8(5, 20, "☑") : u8g2.drawUTF8(5, 20, "☐");

  u8g2.sendBuffer();
}

void screen::drawMode(int mode) {
  char text[20]; 
  sprintf(text, "Mode: %d", mode); 
  u8g2.drawStr(30, 50, text);
}

void screen::changeMode() {
  if(mode <= 1)  mode++; 
  else mode--; 
  show(true);  
}

void screen::update() {

}
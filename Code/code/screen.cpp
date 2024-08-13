#include "screen.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
volatile int lastButtonState = HIGH; 
volatile int buttonState = HIGH; 
volatile unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50; 

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

  u8g2.drawStr(65, 53, "alt");
  u8g2.drawStr(75, 53, "Tab");
  u8g2.drawStr(70, 20, "SS");
  u8g2.drawStr(100, 56, "Copy");
  u8g2.drawStr(100, 21, "Paste");

  /*  Squares  */
  switch(pos) {
  case 1:  
    u8g2.drawRFrame(90, 0, 30, 30, 3); // bottom left
    u8g2.drawRFrame(90, 30, 30, 30, 3); // bottom right
    u8g2.drawRFrame(60, 0, 30, 30, 3); // top left
    u8g2.drawRBox(60, 30, 30, 30, 3);
    break;
  case 2: 
    u8g2.drawRBox(60, 0, 30, 30, 3);
    u8g2.drawRFrame(90, 30, 30, 30, 3); // bottom right
    u8g2.drawRFrame(90, 0, 30, 30, 3); // bottom left
    u8g2.drawRFrame(60, 30, 30, 30, 3); // top right
    break;
  case 3: 
    u8g2.drawRFrame(90, 0, 30, 30, 3); // bottom left
    u8g2.drawRBox(90, 30, 30, 30, 3); 
    u8g2.drawRFrame(60, 0, 30, 30, 3); // top left
    u8g2.drawRFrame(60, 30, 30, 30, 3); // top right
    break;
  case 4: 
    u8g2.drawRFrame(90, 30, 30, 30, 3); // bottom right
    u8g2.drawRFrame(60, 0, 30, 30, 3); // top left
    u8g2.drawRFrame(60, 30, 30, 30, 3); // top right
    u8g2.drawRBox(90, 0, 30, 30, 3);
    break;
  default: 
    u8g2.drawRFrame(90, 0, 30, 30, 3); // bottom left
    u8g2.drawRFrame(90, 30, 30, 30, 3); // bottom right
    u8g2.drawRFrame(60, 0, 30, 30, 3); // top left
    u8g2.drawRFrame(60, 30, 30, 30, 3); // top right
    break;
  }

  /*  Modes  */
  u8g2.drawStr(30, 50,"Mode: 1");

  /*  Key names  */
  // switch(pos) {
  //   case 1:
  //     u8g2.drawStr(70, 20, "SS");
  //     u8g2.drawStr(100, 56, "Copy");
  //     u8g2.drawStr(100, 21, "Paste");
  //   break;
  //   case 2:
  //     u8g2.drawStr(65, 53, "alt");
  //     u8g2.drawStr(75, 53, "Tab");
  //     u8g2.drawStr(100, 56, "Copy");
  //     u8g2.drawStr(100, 21, "Paste");
  //   break;
  //   case 3:
  //     u8g2.drawStr(65, 53, "alt");
  //     u8g2.drawStr(75, 53, "Tab");
  //     u8g2.drawStr(70, 20, "SS"); 
  //     u8g2.drawStr(100, 21, "Paste");
  //   break;
  //   case 4:
  //     u8g2.drawStr(65, 53, "alt");
  //     u8g2.drawStr(75, 53, "Tab");
  //     u8g2.drawStr(70, 20, "SS");
  //     u8g2.drawStr(100, 56, "Copy"); 
  //   break; 
  //   default:
      // u8g2.drawStr(65, 53, "alt");
      // u8g2.drawStr(75, 53, "Tab");
      // u8g2.drawStr(70, 20, "SS");
      // u8g2.drawStr(100, 56, "Copy");
      // u8g2.drawStr(100, 21, "Paste");
  //   break;
  // }

  /*  Header  */
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  isCon == true ? u8g2.drawUTF8(5, 60, "☑") : u8g2.drawUTF8(5, 60, "☐");

  u8g2.sendBuffer();
}



void screen::changeMode() {
  int reading = digitalRead(encoder_pin); 
  // int lastRead = 0; 

  // if(reading != lastRead) {
  //   if(reading == LOW)  Serial.println("Hello");
  //   lastRead = reading; 
  //   while(reading == lastRead)  reading = digitalRead(encoder_pin);
  // }

  // if(reading != lastButtonState) {
  //   lastDebounceTime = millis();
  // }

  // if((millis() - lastDebounceTime) > debounceDelay) {
  //   if(reading != buttonState) {
  //     buttonState = reading; 
  //     if(buttonState == LOW)  Serial.println("Hello");
  //   }
  // }

  // lastButtonState = reading;
}

void screen::update() {

}
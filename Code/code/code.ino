/**
*   This is the main file for the project. It contains the setup and 
*   loop functions for the xiao esp32c3 macropad.
*
*   @file code.ino
*   @author Abdirahman Ahmed Yusuf
*/
#include "functions.h"
#include <esp_sleep.h>

RTC_DATA_ATTR unsigned long lastActiveTime; 

void setup() {
  functions::initKeyPad();
  Serial.begin(115200);

  esp_sleep_wakeup_cause_t wakeupReason = esp_sleep_get_wakeup_cause(); 
  if(wakeupReason == ESP_SLEEP_WAKEUP_EXT1) Serial.println("Woke up!");
  else  Serial.println("Reset or woke up for some other reason...");

  esp_deep_sleep_enable_gpio_wakeup(BIT(D3), ESP_GPIO_WAKEUP_GPIO_LOW);
  lastActiveTime = millis();
}

void loop() {
  if(digitalRead(col_2) == LOW)   functions::checkKeyPad(col_1);
  if(digitalRead(col_1) == LOW)   functions::checkKeyPad(col_2);
  functions::scroll();

  if(isAnythingPressed) {
    lastActiveTime = millis();  isAnythingPressed = false;
  } 
  if(millis() - lastActiveTime > sleep_timeout) {
    screen::clear();
    esp_deep_sleep_start(); 
  }
}
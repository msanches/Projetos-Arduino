#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

boolean ligado = true;

void setup(void) {
  pinMode(12, OUTPUT);
  u8g2.begin();
  Serial.begin(9600);
}

void loop(void) {

  for (int i = 0; i < 2; i++) {
    piscaPisca();
    u8g2.clearBuffer();          // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.drawStr(8, 29, "POMERA"); // write something to the internal memory
    u8g2.sendBuffer();         // transfer internal memory to the display
    delay(800);

    piscaPisca();
    u8g2.clearBuffer();         // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.drawStr(10, 29, "naum"); // write something to the internal memory
    u8g2.sendBuffer();         // transfer internal memory to the display
    delay(600);

    piscaPisca();
    u8g2.clearBuffer();         // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.drawStr(10, 29, "tem"); // write something to the internal memory
    u8g2.sendBuffer();         // transfer internal memory to the display
    delay(600);

    piscaPisca();
    u8g2.clearBuffer();         // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.drawStr(4, 29, "mundial"); // write something to the internal memory
    u8g2.sendBuffer();         // transfer internal memory to the display
    delay(600);
  }

  for (int j = 0; j < 2; j++) {
    piscaPisca();
    u8g2.clearBuffer();         // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.drawStr(10, 29, "naum"); // write something to the internal memory
    u8g2.sendBuffer();         // transfer internal memory to the display
    delay(600);

    piscaPisca();
    u8g2.clearBuffer();         // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.drawStr(10, 29, "tem"); // write something to the internal memory
    u8g2.sendBuffer();         // transfer internal memory to the display
    delay(600);

    piscaPisca();
    u8g2.clearBuffer();         // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.drawStr(4, 29, "copinha"); // write something to the internal memory
    u8g2.sendBuffer();         // transfer internal memory to the display
    delay(600);

    piscaPisca();
    u8g2.clearBuffer();         // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.drawStr(10, 29, "naum"); // write something to the internal memory
    u8g2.sendBuffer();         // transfer internal memory to the display
    delay(600);

    piscaPisca();
    u8g2.clearBuffer();         // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.drawStr(10, 29, "tem"); // write something to the internal memory
    u8g2.sendBuffer();         // transfer internal memory to the display
    delay(600);

    piscaPisca();
    u8g2.clearBuffer();         // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.drawStr(4, 29, "mundial"); // write something to the internal memory
    u8g2.sendBuffer();         // transfer internal memory to the display
    delay(1000);
  }

}

void piscaPisca() {
  if (ligado == true) {
    digitalWrite(12, HIGH);
    ligado = false;
  } else {
    digitalWrite(12, LOW);
    ligado = true;
  }
}

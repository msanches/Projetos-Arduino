//https://github.com/olikraus/u8g2/wiki/u8g2reference

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 

int analogPin = 0; // pino do LM35 (sensor de temperatura)
int valAnalog;
int temperatura;
int temp;

void setup(void) {
   u8g2.begin();
}

void loop(void) {
    valAnalog = analogRead(analogPin);
    temp = ( 5 * valAnalog * 100) / 1024 ;
    if(temp > 0){
      temperatura = temp;
    }
    
//   u8g2.clearBuffer();					// clear the internal memory
//   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
//   u8g2.drawStr(8,29,"MARCO");	// write something to the internal memory
//   u8g2.sendBuffer();					// transfer internal memory to the display
//   delay(3000);

//   u8g2.clearBuffer();         // clear the internal memory
//   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
//   u8g2.drawStr(10,29,"eh um");  // write something to the internal memory
//   u8g2.sendBuffer();         // transfer internal memory to the display
//   delay(800);
//
//   u8g2.clearBuffer();         // clear the internal memory
//   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
//   u8g2.drawStr(10,29,"cara");  // write something to the internal memory
//   u8g2.sendBuffer();         // transfer internal memory to the display
//   delay(800);
//
//   u8g2.clearBuffer();         // clear the internal memory
//   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
//   u8g2.drawStr(4,29,"legal");  // write something to the internal memory
//   u8g2.sendBuffer();         // transfer internal memory to the display
//   delay(2000);
   
    u8g2.clearBuffer();         // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso28_tr); // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.setCursor(4, 29);
    u8g2.print(temperatura);
    u8g2.drawCircle(47,8,4);
    u8g2.drawStr( 54, 29, "C");
    u8g2.sendBuffer(); // transfer internal memory to the display
    delay(5000);
  
}

//https://github.com/olikraus/u8g2/wiki/u8g2reference

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 

#include <IRremote.h>
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  u8g2.begin();
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  u8g2.clearBuffer();          // clear the internal memory
   u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
   u8g2.drawStr(8,29,"Press...");  // write something to the internal memory
   u8g2.sendBuffer();         // transfer internal memory to the display
   //delay(3000);
}

void loop() {
  if (irrecv.decode(&results)){

    Serial.print("Endereço HEX: ");
    Serial.print(results.value,HEX);
    Serial.println("");
    Serial.print("Endereço Dec: ");
    Serial.println(results.value);
    
    draw(results.value);
    
    if(results.value == 3772784863){
        digitalWrite(12,HIGH);
        delay(1000);
    } else if(results.value == 3772817503){
        digitalWrite(12,LOW);
        delay(1000);
    }
    irrecv.resume();
    }
}

void draw(int value){
    u8g2.clearBuffer();         // clear the internal memory
    u8g2.setFont(u8g2_font_10x20_tn); // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
    u8g2.setCursor(4, 29);
    u8g2.print(value);
    u8g2.sendBuffer(); // transfer internal memory to the display
   // delay(3000);
}

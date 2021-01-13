#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NO_ACK);	// Display which does not send ACK

int analogPin = 0; // pino do LM35 (sensor de temperatura)
int valAnalog;
int temperatura;

void draw() {
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0, 20); 
  valAnalog = analogRead(analogPin);
  temperatura = ( 5 * valAnalog * 100) / 1024 ;
  Serial.println(temperatura);
  //Seleciona a fonte de texto
  u8g.setFont(u8g_font_8x13B);
  //u8g.setFont(u8g_font_fur25);
  //Linha superior - temperatura 
  u8g.setPrintPos(5, 15);
  u8g.print(temperatura);
  u8g.drawCircle(28,8,3);
  u8g.drawStr( 34, 15, "C");
  u8g.setFont(u8g_font_fub25);
  u8g.drawStr( 8, 57, "Marco");
  //moldura
  u8g.drawRFrame(0,20, 125, 44, 4);
}

void setup() {
  // flip screen, if required
  //u8g.setRot180();
  Serial.begin(9600);
}

void loop() {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(3000);
}

#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_GFX.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_SSD1306.h> //INCLUSÃO DE BIBLIOTECA

// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
//                          yellow , orange

Adafruit_SSD1306 display = Adafruit_SSD1306(); //OBJETO DO TIPO Adafruit_SSD1306

void setup(){
  Wire.begin(); //INICIALIZA A BIBLIOTECA WIRE
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //INICIALIZA O DISPLAY COM ENDEREÇO I2C 0x3C
  display.setTextColor(WHITE); //DEFINE A COR DO TEXTO
  display.setTextSize(1); //DEFINE O TAMANHO DA FONTE DO TEXTO
  display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
}
void loop() {
  display.setCursor(0,0); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("O Marcantonyo"); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  delay(1500); //INTERVALO DE 1,5 SEGUNDOS
  //display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
  display.setCursor(32,10); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("se preocupa"); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  delay(1500); //INTERVALO DE 1,5 SEGUNDOS
  display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
  display.setCursor(37,10); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("com o seu"); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  delay(1500); //INTERVALO DE 1,5 SEGUNDOS
  display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
  display.setCursor(32,10); //POSIÇÃO EM QUE O CURSOR IRÁ FAZER A ESCRITA
  display.print("aprendizado!"); //ESCREVE O TEXTO NO DISPLAY
  display.display(); //EFETIVA A ESCRITA NO DISPLAY
  delay(1500); //INTERVALO DE 1,5 SEGUNDOS
  display.clearDisplay(); //LIMPA AS INFORMAÇÕES DO DISPLAY
}

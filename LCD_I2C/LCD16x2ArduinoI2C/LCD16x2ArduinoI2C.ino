/* Programa de Teste de LCD - Interafce I2C
   Blog Eletrogate - http://blog.eletrogate.com/guia-completo-do-display-lcd-arduino/
   Arduino Nano - LCD 16/2 azul - IDE 1.8.5
   Gustavo Murta   13/abril/2018
   Biblioteca LiquidCrystal  https://github.com/marcoschwartz/LiquidCrystal_I2C
*/


#include <Wire.h>                     // usando a biblioteca Wire
#include <LiquidCrystal_I2C.h>        // usando a biblioteca LiquidCrystal I2C

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Configura endereço I2C e display com 16 caracteres e 2 linhas 
int thisChar = 0 ;

void setup()
{
  lcd.init();                      // inicializa LCD
  lcd.backlight();                 // ativa led de backlight
}

void Hello ()                     // imprimindo mensagem
{
  lcd.setCursor(0, 0);            // selecionando coluna 0 e linha 0
  lcd.print("Blog ELETROGATE");   // print da mensagem
  lcd.setCursor(2, 1);            // selecionando coluna 2 e linha 1
  lcd.print("Guia do LCD");       // Print da mensagem
  delay(1000);                    // atraso de 1 segundo
}

void Flash ()
{
  lcd.noDisplay();                // desliga display
  delay(1000);                    // atraso de meio segundo
  lcd.display();                  // liga display
  delay(1000);                    // atraso de meio segundo
  lcd.clear();                    // limpa a tela
  delay(1000);                    // atraso de 1 segundo
}

void Blink ()                     // teste do cursor
{
  lcd.noBlink();                  // apaga cursor
  delay(1000);                    // atraso de 1 segundo
  lcd.blink();                    // acende cursor
  delay(1000);                    // atraso de 1 segundo
  lcd.clear();                    // limpa a tela
  delay(1000);                    // atraso de 1 segundo
}

void AutoScroll ()                // teste de rolagem de mensagem
{
  lcd.setCursor(16, 1);           // selecionando coluna 16 e linha 1
  lcd.autoscroll();               // configura rolagem automatica de mensagem
  for (thisChar = 0; thisChar < 10; thisChar++)     // imprime de 0 a 9
  {
    lcd.print(thisChar);          // imprime o numero
    delay(350);                   // atraso de 350 ms
  }
  lcd.noAutoscroll();             // desliga rolagem autoamtica
  lcd.clear();                    // limpa a tela
  delay(1000);                    // atraso de 1 segundo
}

void dirText ()                   // teste de direcao de mensagem
{
  lcd.clear();                    // limpa a tela
  lcd.cursor();                   // liga o cursor
  lcd.setCursor(10, 0);           // selecionando coluna 10 e linha 1
  for (thisChar = 1; thisChar < 10; thisChar++)     // imprime de 1 a 9
  {
    lcd.rightToLeft();            // imprime da direita para a esquerda
    lcd.print(thisChar);          // imprime o numero
    delay(350);                   // atraso de 350 ms
  }
  for (thisChar = 1; thisChar < 10; thisChar++)     // imprime de 1 a 9
  {
    lcd.leftToRight();            // imprime da esquerda para a direita
    lcd.print(thisChar);          // imprime o numero
    delay(350);                   // atraso de 350 ms
  }
  lcd.noCursor();                 // desliga o cursor
}

void loop()
{
  Hello ();         // imprimindo mensagem
  Flash ();         // piscando a mensagem
  Blink ();         // teste do cursor
  AutoScroll ();    // teste de rolagem de mensagem
  dirText ();       // teste de direcao de mensagem
  delay(1000);      // atraso de 1 segundo
}

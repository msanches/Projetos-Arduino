
#include <Wire.h>                     // usando a biblioteca Wire
#include <LiquidCrystal_I2C.h>        // usando a biblioteca LiquidCrystal I2C

int analogPin = 0;
float valAnalog;
float temperatura;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Configura endereço I2C e display com 16 caracteres e 2 linhas 

void setup() {
  lcd.init();                      // inicializa LCD
  lcd.backlight();                 // ativa led de backlight
  lcd.setCursor(0, 0);            // selecionando coluna 0 e linha 0
  lcd.print("Temperatura:");   // print da mensagem
}

void loop() {
  valAnalog = analogRead(analogPin);
  temperatura = ( 5 * valAnalog * 100) / 1024 ;
  lcd.setCursor(0, 1);            // selecionando coluna 2 e linha 1
  lcd.print(temperatura);       // Print da mensagem
  lcd.print(" C");
  delay(500);
}

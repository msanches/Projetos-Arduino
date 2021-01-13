// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*Temperatura em Celsius*/
int analogPin = 0; // lm35 está ligado ao a entrada analogica 0
float valAnalog; // variavel para armazenar o valor analogico lido
float temperatura;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temperatura: ");
  Serial.begin(9600);
}

void loop() {
  valAnalog = analogRead(analogPin);
  temperatura = ( valAnalog * 500) / 1024;
  lcd.setCursor(0, 1);
  lcd.print(temperatura);
  lcd.print(" C");
  delay(1000); //atualiza a cada 1 segundo
}

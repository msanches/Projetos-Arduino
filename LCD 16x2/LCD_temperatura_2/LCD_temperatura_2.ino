#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Declarando o Sensor
int sensor = 0; // lm35 está ligado ao a entrada analogica 0
float valAnalog = 0 ; // variavel para armazenar o valor analogico lido
float temperatura = 0 ;

void setup() {
  lcd.begin(16, 2); //LCD 16x2
  lcd.print("Temperatura: "); //Saída para o LCD
  Serial.begin(9600); //Saída para o Serial Monitor
  Serial.println("Temperatura:");
}

void loop() {
  // Cálculo para o sensor
  valAnalog = analogRead(sensor);
  temperatura = (valAnalog * 500)/1024;
  Serial.print(temperatura); // Apresentação do resultado/temperatura no Serial Monitor
  Serial.println(" C");
  lcd.setCursor(0, 1); // Colocando o cursor na coluna 0 e linha 1
  lcd.print(temperatura); // Apresentação do resultado/temperatura no LCD
  lcd.print(" C");
  delay(1000); // atualização dos dados a cada 1 segundo
}

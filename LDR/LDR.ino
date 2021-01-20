#include <Wire.h>                     // usando a biblioteca Wire
#include <LiquidCrystal_I2C.h>        // usando a biblioteca LiquidCrystal I2C

int sensor = A1; //Entrada analógica do LDR
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Configura endereço I2C e display com 16 caracteres e 2 linhas 

void setup() {
  pinMode(sensor, INPUT);
  lcd.init();                      // inicializa LCD
  lcd.backlight();                 // ativa led de backlight
  lcd.setCursor(0,0);
  lcd.print("LDR");
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(sensor);
  Serial.println(valor);
  lcd.setCursor(0, 1); 
  lcd.println(valor);
  delay(1000); //Delay de 1 s - opcional para atrasar mediçoes
}

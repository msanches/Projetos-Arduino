#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Declarando o Sensor
int SENSOR = 0; // lm35 está ligado ao a entrada analogica 0
float D = 0 ; // variavel para armazenar o valor analogico lido
float T = 0 ;

void setup() {
lcd.begin(16, 2); //LCD 16x2
lcd.print("Temp.");
Serial.begin(9600); //Saída para o Serial Monitor
Serial.println("Temp.");
}

void loop() {
lcd.setCursor(0, 1); // Colocando o cursor na coluna 0 e linha 1
// Cálculo para o sensor
D = analogRead(SENSOR);
T = (D * 500)/1023;
Serial.print(T); // Apresentação do resultado/temperatura no Serial Monitor
Serial.println(" C");
lcd.print(T); // Apresentação do resultado/temperatura no LCD
lcd.print(" C");
delay(5000); // atualização dos dados a cada 1 segundo
}

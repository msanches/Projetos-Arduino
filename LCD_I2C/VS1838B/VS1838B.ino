#include <IRremote.h>
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

#include <Wire.h>                     // usando a biblioteca Wire
#include <LiquidCrystal_I2C.h>        // usando a biblioteca LiquidCrystal I2C

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Configura endereço I2C e display com 16 caracteres e 2 linhas 


 void setup(){
  pinMode(12,OUTPUT);
  lcd.init();                      // inicializa LCD
  lcd.backlight();                 // ativa led de backlight
  lcd.setCursor(0, 0);            // selecionando coluna 0 e linha 0
  lcd.print("Endereco Hex: ");   // print da mensagem
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop(){
  if (irrecv.decode(&results)){
    Serial.print("Endereço HEX: ");
    Serial.print(results.value,HEX);
    Serial.println("");
    Serial.print("Endereço Dec: ");
    Serial.println(results.value);

    lcd.setCursor(0, 1);            // selecionando coluna 2 e linha 1
    lcd.print(results.value,HEX);       // Print da mensagem

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

#include <LiquidCrystal.h>
#define echoPin 8 //Pino 13 recebe o pulso do echo
#define trigPin 13 //Pino 12 envia o pulso para gerar o echo

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup()
{
   lcd.begin(16, 2); //LCD 16x2
   lcd.print("Distancia em cm");
   Serial.begin(9600); //inicia a porta serial
   pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)
   pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)
}

void loop()
{
    lcd.setCursor(0, 1);// Colocando o cursor na coluna 0 e linha 1
  //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
    digitalWrite(trigPin, LOW);
  // delay de 2 microssegundos
    delayMicroseconds(2);
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
    digitalWrite(trigPin, HIGH);
  //delay de 10 microssegundos
    delayMicroseconds(10);
  //seta o pino 12 com pulso baixo novamente
    digitalWrite(trigPin, LOW);
  //pulseInt lê o tempo entre a chamada e o pino entrar em high
    long duration = pulseIn(echoPin,HIGH);
  //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado
  //porque é o tempo de ida e volta do ultrassom
    long distancia = duration /29 / 2 ;

Serial.print("Distancia em CM: ");
Serial.println(distancia);
lcd.print(distancia); // Apresentação do resultado no LCD
delay(1000); //espera 1 segundo para fazer a leitura novamente
}

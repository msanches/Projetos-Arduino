// Programa: Sensor DHT11 - Envio de dados via Bluetooth
// Autor: FILIPEFLOP
#include <SoftwareSerial.h>

SoftwareSerial hc06(2,3);
#include "DHT.h"
#define dht_pin A5 //Pino DATA do Sensor ligado na porta Analogica A5
#define DHTTYPE DHT11
DHT dht(dht_pin, DHTTYPE);
 
void setup()
{
  Serial.begin(9600);
  // Aguarda 1 seg antes de acessar as informações do sensor
  delay(1000);
  dht.begin();
  hc06.begin(9600);
}
 
void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // Mostra os valores lidos, na serial
  Serial.print("Temp. = ");
  Serial.print(t);
  Serial.print("ºC ");
  Serial.print("Um. = ");
  Serial.print(h);
  Serial.println("% ");

  // Mostra os valores lidos, no bluetooth
  hc06.print("Temp. = ");
  hc06.print(t);
  hc06.print("ºC ");
  hc06.print("Um. = ");
  hc06.print(h);
  hc06.println("% ");

  // Nao diminuir muito o valor abaixo
  // O ideal e a leitura a cada 2 segundos
  delay(2000);
}

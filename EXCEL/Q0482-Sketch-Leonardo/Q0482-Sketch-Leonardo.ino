/*
     Q0482-Sketch.ino
     AUTOR:   BrincandoComIdeias
     LINK:    https://www.youtube.com/brincandocomideias ; https://cursodearduino.net/
     COMPRE:  https://www.arducore.com.br/
     SKETCH:  Data Logger com Envio ao Excel via Teclado (Para Arduino Leonardo ou Compatível)
     DATA:    20/07/2019

   ATUALIZACAO: em ../../.... por .... o que .......

*/
//SENSOR DE TEMPERATURA E HUMIDADE RELATIVA
#include <dht.h>

//RELOGIO RTC
#include <Wire.h>
#include "RTClib.h"

//OBJETO PARA EMULADOR DE TECLADO (ARDUINO LEONARDO OU COMPATIVEL)
#include <Keyboard.h>

//CRIACAO DOS OBJETOS
dht DHT;
RTC_DS3231 rtc;

//PINAGEM DO CIRCUITO
#define pinPause 12 //define o pino de pausa
#define DHT22_PIN 4
//o RTC deve ser ligado nas portas I2C (SDA e SCK). Verifique o diagrama de pinos do seu Arduino.

//VARIAVEIS GLOBAIS
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};

//DECLARACAO DAS FUNCOES
void estadoPause();
void erroCritico();
void teclaEnter();
void teclaTAB();

//EXECUTADO QUANDO O ARDUINO FOR LIGADO
void setup() {
  //INICIO DOS PINOS
  pinMode(pinPause, INPUT_PULLUP); //pino para pausar o envio 

  //INICIA RTC
  if (! rtc.begin()) {
    erroCritico();
  }

  //A LINHA DE BAIXO É USADA APENAS PARA AJUSTAR O HORARIO DO RTC APARTIR DA HORA DO COMPUTADOR
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  //INICIO DO EMULADOR DE TECLADO
  Keyboard.begin();
}

//EXECUTADO REPETIDAMENTE APÓS A EXECUCAO DO SETUP
void loop() {

  //PARA FACILITAR FUTURAS CARGAS
  if (!digitalRead(pinPause)) {
    estadoPause();
    return;
  }

  DateTime now = rtc.now();

  Keyboard.print( daysOfTheWeek[now.dayOfTheWeek()] );
  teclaTAB();

  Keyboard.print(now.hour());
  Keyboard.print(':');
  Keyboard.print(now.minute());
  Keyboard.print(':');
  Keyboard.print(now.second());
  teclaTAB();

  Keyboard.print(now.day());
  Keyboard.print('/');
  Keyboard.print(now.month());
  Keyboard.print('/');
  Keyboard.print(now.year());
  teclaTAB();

  int chk = DHT.read22(DHT22_PIN);
  if (chk == DHTLIB_OK) {

    String umidade_string;
    umidade_string = String(DHT.humidity, 2);
    umidade_string.replace(".", ",");

    Keyboard.print(umidade_string);
    teclaTAB();

    String temperatura_string;
    temperatura_string = String(DHT.temperature, 2);
    temperatura_string.replace(".", ",");

    Keyboard.print(temperatura_string);
    teclaTAB();
  }

  teclaEnter();

  delay(2000);
}

//FUNCAO PARA AGUARDAR ANTES DE INICIAR O SETUP PARA NAO PROJUDICAR FUTURAS CARGAS
void estadoPause() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(900);                       // wait for a second
}

//FUNCAO PARA AVISO DE ERRO CRITICO ATRAVES DO LED INTERNO DO ARDUINO
void erroCritico() {
  pinMode(LED_BUILTIN, OUTPUT);
  while (true) {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(200);                       // wait for a second
  }
}

//FUNCAO PARA ENVIAR O APERTO DE UM ENTER
void teclaEnter() {
  Keyboard.press(KEY_RETURN);   // PRESSIONA O ENTER
  delay(50);                   // ESPERA 100 MILISSEGUNDOS
  Keyboard.release(KEY_RETURN); // SOLTA O ENTER
}

//FUNCAO PARA ENVIAR O APERTO DE UM TAB
void teclaTAB() {
  Keyboard.press(KEY_TAB);   // PRESSIONA O TAB
  delay(50);                // ESPERA 100 MILISSEGUNDOS
  Keyboard.release(KEY_TAB); // SOLTA O TAB
}

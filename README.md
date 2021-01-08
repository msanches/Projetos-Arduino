# Projetos com Arduino
![](http://dwebkit.esy.es/repositorio/Arduino/Arduino_logo.png)
## Sobre o Arduino

> Segundo a Wikipédia Arduino é uma plataforma de prototipagem eletrônica de hardware livre e de placa única, projetada com um microcontrolador Atmel AVR com suporte de entrada/saída embutido, uma linguagem de programação padrão, a qual tem origem em Wiring, e é essencialmente C/C++. [Leia mais em Wikepédia](https://pt.wikipedia.org/wiki/Arduino)

## Exemplos e tutoriais utilizando o Arduino
Habitualmente, o primeiro programa que é executado tem a simples função de piscar um LED. No ambiente de desenvolvimento, o utilizador escreve um programa exemplo como este:
```c++
// define LED_PIN 13
int LED_PIN = 13;

void setup () {
    pinMode (LED_PIN, OUTPUT);     // habilita o pino 13 para saída digital (OUTPUT).
}

void loop () {
    digitalWrite (LED_PIN, HIGH);  // liga o LED.
    delay (1000);                  // espera 1 segundo (1000 milissegundos).
    digitalWrite (LED_PIN, LOW);   // desliga o LED.
    delay (1000);                  // espera 1 segundo.
}
```

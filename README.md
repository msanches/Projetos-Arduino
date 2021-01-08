# Projetos com Arduino
![](http://dwebkit.esy.es/repositorio/Arduino/Arduino_logo.png)
## Sobre o Arduino

> Segundo a Wikipédia Arduino é uma plataforma de prototipagem eletrônica de hardware livre e de placa única, projetada com um microcontrolador Atmel AVR com suporte de entrada/saída embutido, uma linguagem de programação padrão, a qual tem origem em Wiring, e é essencialmente C/C++. [Leia mais em Wikepédia](https://pt.wikipedia.org/wiki/Arduino)

## Exemplos e tutoriais utilizando o Arduino
Assim como o famoso "Hello World" ou "Olá Mundo", em geral, o primeiro programa executado no **Arduino** tem a simples função de piscar um LED. No ambiente de desenvolvimento, programa para executar esse exemplo seria o seguinte:
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
> Veja esse exemplo completo [clicando aqui](https://github.com/msanches/Projetos-Arduino/tree/main/PiscaLed)

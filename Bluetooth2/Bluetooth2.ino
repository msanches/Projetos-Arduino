#define SOFT_RX 2
#define SOFT_TX 3
#define SOFT_SERIAL_SPEED 9600

#include <SoftwareSerial.h>

SoftwareSerial bluetooth(SOFT_RX, SOFT_TX);

void setup(){
    Serial.begin(9600);
    Serial.println("Pronto para comandos");
    bluetooth.begin(SOFT_SERIAL_SPEED);
    bluetooth.println("Bluetooth ready");
}

void loop(){
    /* le de uma, imprime n outra, mas por ser byte a byte, nao deve-se
       esquecer de colocar \r\n (ou retorno de   carro e nova linha, ou
       CR/NL, ou como quiser chamar. Opcao no  rodape do monitor serial
       da IDE do Arduino)
    */
    if (bluetooth.available()){
        char ch = (char)bluetooth.read();
       Serial.write(ch);
    }
    if (Serial.available()){
        char ch =  (char)Serial.read();
        bluetooth.write(ch);
    }
}

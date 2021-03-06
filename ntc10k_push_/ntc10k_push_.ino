#include <Thermistor.h> //INCLUSÃO DA BIBLIOTECA
 
Thermistor temp(6); //VARIÁVEL DO TIPO THERMISTOR, INDICANDO O PINO ANALÓGICO (A6) EM QUE O TERMISTOR ESTÁ CONECTADO
// VERIFICAR QUAL O PINO ANALÓGICO NO SEU ARDUINO
int Botao = 0;
bool ligado = false;

void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL
  delay(1000); //INTERVALO DE 1 SEGUNDO
}
void loop() {
  Botao = digitalRead(8);
  if(Botao == 0){
    ligado = !ligado;
  }
  if(ligado == true){
    float temperature = temp.getTemp(); //VARIÁVEL DO TIPO INTEIRO QUE RECEBE O VALOR DE TEMPERATURA CALCULADO PELA BIBLIOTECA
    Serial.print("Temperatura: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(temperature); //IMPRIME NO MONITOR SERIAL A TEMPERATURA MEDIDA
    Serial.println("ºC"); //IMPRIME O TEXTO NO MONITOR SERIAL  
  }
  
  delay(1000); //INTERVALO DE 1 SEGUNDO
}

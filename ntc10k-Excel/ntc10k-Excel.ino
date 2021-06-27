#include <Thermistor.h> //INCLUSÃO DA BIBLIOTECA
#include <Keyboard.h> 
Thermistor temp(6); //VARIÁVEL DO TIPO THERMISTOR, INDICANDO O PINO ANALÓGICO (A6) EM QUE O TERMISTOR ESTÁ CONECTADO
// VERIFICAR QUAL O PINO ANALÓGICO NO SEU ARDUINO
int Botao = 0;
bool ligado = false;
float temperatura = 0;
int i = 0;

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
    i++;
    temperatura = temp.getTemp(); //VARIÁVEL DO TIPO INTEIRO QUE RECEBE O VALOR DE TEMPERATURA CALCULADO PELA BIBLIOTECA
    Keyboard.print(i);
    teclaTab();
    Keyboard.print(temperatura); //IMPRIME NO MONITOR SERIAL A TEMPERATURA MEDIDA
    teclaEnter();
  }
  
  delay(3000); //INTERVALO DE 1 SEGUNDO
}

void teclaEnter(){
  Keyboard.press(KEY_RETURN);
  delay(50);
  Keyboard.release(KEY_RETURN);
  }
void teclaTab(){
  Keyboard.press(KEY_TAB);
  delay(50);
  Keyboard.release(KEY_TAB);
  }

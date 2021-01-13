#include <Keypad.h> //INCLUSÃO DE BIBLIOTECA

#include <Wire.h>                     // usando a biblioteca Wire
#include <LiquidCrystal_I2C.h>        // usando a biblioteca LiquidCrystal I2C

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Configura endereço I2C e display com 16 caracteres e 2 linhas 

const byte qtdLinhas = 4; //QUANTIDADE DE LINHAS DO TECLADO
const byte qtdColunas = 4; //QUANTIDADE DE COLUNAS DO TECLADO

//CONSTRUÇÃO DA MATRIZ DE CARACTERES
char matriz_teclas[qtdLinhas][qtdColunas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte PinosqtdLinhas[qtdLinhas] = {3, 4, 5, 6}; //PINOS UTILIZADOS PELAS LINHAS
byte PinosqtdColunas[qtdColunas] = {8, 9, 10,11}; //PINOS UTILIZADOS PELAS COLUNAS

 float Num1, Num2, Number;
 char key, action = '+';
 boolean result = false;
 
//INICIALIZAÇÃO DO TECLADO
Keypad meuteclado = Keypad( makeKeymap(matriz_teclas), PinosqtdLinhas, PinosqtdColunas, qtdLinhas, qtdColunas); 

void setup(){
  lcd.init();                      // inicializa LCD
  lcd.backlight();                 // ativa led de backlight
  lcd.print("DIY Calculator"); //Display a intro message
  lcd.setCursor(1, 1);   // set the cursor to column 0, line 1
  lcd.print("Macontony"); //Display a intro message 

  delay(2000); //Wait for display to show info
  lcd.clear(); //Then clean 

  Serial.begin(9600); //INICIALIZA A SERIAL
  Serial.println("Aperte uma tecla..."); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println(); //QUEBRA UMA LINHA NO MONITOR SERIAL
}
  
void loop(){
  key = meuteclado.getKey(); //VERIFICA SE ALGUMA DAS TECLAS FOI PRESSIONADA

  if( key != NO_KEY)
    DetectaKey();

  if (result==true)
    CalculaResult();
 
  DisplayResult();
}

void DetectaKey(){
    if (key=='*'){
      Serial.println ("Button Cancel"); 
      Number = Num1 = Num2 = 0; 
      lcd.clear();
      result = false;
    }
    if (key == '1'){
      if (Number==0)
        Number=1;
      else
        Number = (Number*10) + 1; //Pressed twice
    }
    if (key == '2'){
      if (Number==0)
        Number=2;
      else
        Number = (Number*10) + 2; //Pressed twice
    }
    if (key == '3'){
      if (Number==0)
        Number=3;
      else
        Number = (Number*10) + 3; //Pressed twice
    }
    if (key == '4'){
      if (Number==0)
        Number=4;
      else
        Number = (Number*10) + 4; //Pressed twice
    }
    if (key == '5'){
      if (Number==0)
        Number=5;
      else
        Number = (Number*10) + 5; //Pressed twice
    }
    if (key == '6'){
      if (Number==0)
        Number=6;
      else
        Number = (Number*10) + 6; //Pressed twice
    }
    if (key == '7'){
      if (Number==0)
        Number=7;
      else
        Number = (Number*10) + 7; //Pressed twice
    }        
    if (key == '8'){
      if (Number==0)
        Number=8;
      else
        Number = (Number*10) + 8; //Pressed twice
    }
    if (key == '9'){
      if (Number==0)
        Number=9;
      else
        Number = (Number*10) + 9; //Pressed twice
    }
    if (key == '0'){
      if (Number==0)
        Number=0;
      else
        Number = (Number*10) + 0; //Pressed twice
    }
    if (key == '#'){
      Num2 = Number;
      result = true;
    }
    if (key == 'A' || key == 'B' || key == 'C' || key == 'D'){
      Num1 = Number;    
      Number =0;
      if (key == 'A')
        action = '+';
      if (key == 'B')
        action = '-';
      if (key == 'C')
        action = '*';
      if (key == 'D')
        action = '/';
      delay(100);
  }
               
}

void CalculaResult(){
  if (action=='+')
    Number = Num1+Num2;
  if (action=='-')
    Number = Num1-Num2;

  if (action=='*')
    Number = Num1*Num2;

  if (action=='/')
    Number = Num1/Num2; 
}

void DisplayResult(){
  lcd.setCursor(0, 0);   // set the cursor to column 0, line 1
  lcd.print(Num1); 
  lcd.print(action); 
  lcd.print(Num2); 
  if(result == true){
    lcd.print(" = "); 
    lcd.print(Number);
  }
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print(Number); //Display the result
}

/* Temperatura em Celsius */

int analogPin = 0;
float valAnalog;
float temperatura = 0;
int linha = 0;  // variavel que se refere as linhas do excel
int LABEL = 1;

void setup() {
  Serial.begin(9600); 
  Serial.println("CLEARDATA");                        // Reset da comunicação serial
  Serial.println("LABEL,Linha,Tempo,Temperatura");   // Nomeia as colunas
}

void loop() {
//  if (linha > 20){ //laço para limitar a quantidade de dados
//    linha = 0;
//    Serial.println("ROW,SET,2"); // alimentação das linhas com os dados sempre iniciando
//  }
  
  while(linha < 20){
    imprimeDados();
  }

}

void imprimeDados(){
  valAnalog = analogRead(analogPin);
  temperatura = ( 5 * valAnalog * 100) / 1024 ;
  
  linha++; // incrementa a linha do excel para que a leitura pule de linha em linha
  Serial.print("DATA,"); //inicia a impressão de dados 
  Serial.print(linha); // nº da linha
  Serial.print(",");
  Serial.print("TIME,"); //inicia a impressão de dados, sempre iniciando 
  Serial.println(temperatura);
  
  delay(2000);  // espera 2 segundos
}

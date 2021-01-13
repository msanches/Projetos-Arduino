int sensor = A1; //Entrada analógica do LDR
int linha = 0;  // variavel que se refere as linhas do excel

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);

  Serial.println("CLEARDATA");                        // Reset da comunicação serial
  Serial.println("LABEL,Linha,Data,Hora,Valor");   // Nomeia as colunas
}

void loop() {
  int valor = analogRead(sensor);
  Serial.println(valor);

  linha++; // incrementa a linha do excel para que a leitura pule de linha em linha
  Serial.print("DATA,"); //inicia a impressão de dados 
  Serial.print(linha); // nº da linha
  Serial.print(",DATE, TIME,"); // imprime a data e a hora do sistema
  Serial.println(valor); // imprime o valor lido pelo sensor
  
  delay(1000); //Delay de 5 s - opcional para atrasar mediçoes
}

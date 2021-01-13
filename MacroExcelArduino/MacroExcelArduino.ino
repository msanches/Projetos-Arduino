#define RESOLUCAO 200
int sensorValue;

void setup() {
  Serial.begin(9600);
}

void loop() {
    sensorValue = analogRead(A0); //lê o dado da porta analógica
    Serial.write(sensorValue);
    Serial.print('\n');
    delay(RESOLUCAO); //espera x milisegundos
}

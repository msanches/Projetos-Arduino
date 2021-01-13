int sensor = A1; //Entrada analógica do LDR

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(sensor);
  Serial.println(valor);
  delay(1000); //Delay de 1 s - opcional para atrasar mediçoes
}

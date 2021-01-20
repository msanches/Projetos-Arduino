

int sensor = A1; //Entrada analógica do LDR

void setup() {
  pinMode(sensor, INPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(sensor);
  Serial.println(valor);
  if(valor <= 200){
      digitalWrite(12,HIGH);
  } else {
      digitalWrite(12,LOW);
  }
  delay(1000);
}

int Botao = 0;
int i = 0;

void setup()
{
  pinMode(4, INPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Botao = digitalRead(4);
  if (Botao == 0) {
    digitalWrite(12, HIGH);
    i++;
    Serial.println(i);
  } else {
    digitalWrite(12, LOW);
  }
  delay(200); // Delay a little bit to improve simulation performance
}

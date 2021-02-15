boolean ligado = false;

void setup()
{
  pinMode(4, INPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  pausa();
  delay(500); // Wait for 1000 millisecond(s)
}

void pausa() {
  if (digitalRead(4) == 0) {
    ligado = !ligado;
  }

  if (ligado) {
    digitalWrite(12, HIGH);
    Serial.println("Palmeira não tem mundial");
  } else {
    digitalWrite(12, LOW);
  }
}

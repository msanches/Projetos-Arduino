/* Temperatura em Celsius */

int analogPin = 0;
float valAnalog;
float temperatura;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  valAnalog = analogRead(analogPin);
  temperatura = ( 5 * valAnalog * 100) / 1024 ;
  Serial.print(temperatura);
  Serial.println(" C");
  delay(600) ;
}

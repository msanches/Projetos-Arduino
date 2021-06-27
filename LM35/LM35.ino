const int sensorPin = A0; //pino do sensor
float temperatura = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  temperatura = (analogRead(sensorPin)*0.0048828125 * 100);
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println("ºC");
  delay(1000);
}

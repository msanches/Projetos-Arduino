//Projeto arduino pisca led
 
void setup() {
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,LOW);
  delay(1000);
  Serial.println("Hello");
}

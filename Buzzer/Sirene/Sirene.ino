float seno;
int frequencia;
void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int x=0; x<180; x++){
    seno=(sin(x*3.1416/160));
    frequencia = 2000+(int(seno*1000));
    tone(7,frequencia);
    delay(2);
  }
}

// Projeto 11 - Dó Ré Mi
 
#define DO  262
#define RE  294
#define MI  330
#define FA  349
#define SOL  392
#define LA  440
#define SI  494
#define DO_2  523
 
int pinoBuzzer = 6;
 
int melodia[] = {
  DO, RE, MI, FA, SOL, LA, SI, DO_2
};
 
void setup() {
   // configura pino do buzzer como saída
  pinMode(pinoBuzzer,OUTPUT);
}
 
void loop() {
  for(int i=0; i<8; i++)
  {
    tone(pinoBuzzer, melodia[i]);
    delay(500);
  }
}

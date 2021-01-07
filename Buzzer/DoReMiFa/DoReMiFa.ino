#define BUZZER 7
int notas1[] = { 524, 588, 660, 699, 699, 699, 524, 588, 524, 588, 588, 588 , 524, 785, 699, 660, 660, 660, 524, 588, 660, 699, 699, 699 };
void setup() {
pinMode(BUZZER, OUTPUT);
}
void loop() {
for (int i = 0; i < 24; i++) {
tone(BUZZER, notas1[i], 900);
delay(900);
}
delay(1000);
}

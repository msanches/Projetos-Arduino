#include <IRremote.h>
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

 void setup(){
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop(){
  if (irrecv.decode(&results)){
    Serial.print("Endereço HEX: ");
    Serial.print(results.value,HEX);
    Serial.println("");
    Serial.print("Endereço Dec: ");
    Serial.println(results.value);

    if(results.value == 3772784863){
        digitalWrite(12,HIGH);
        delay(1000);
    } else if(results.value == 3772817503){
        digitalWrite(12,LOW);
        delay(1000);
    }
    
    irrecv.resume();
    }
}

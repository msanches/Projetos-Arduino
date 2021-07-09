#include <SoftwareSerial.h>
SoftwareSerial hc06(2,3);

void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
}

void loop(){
  //Write data from HC06 to Serial Monitor
  if (hc06.available()){
    char c = (char)hc06.read();
    Serial.write(c);
  }
  
  //Write from Serial Monitor to HC06
  if (Serial.available()){
    char c = (char)Serial.read();
    hc06.write(c);
  }  
}

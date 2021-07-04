#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
}

void loop() {
  // put your main code here, to run repeatedly:
   byte btn = MFS.getButton();

  if (btn)
  {
    byte buttonNumber = btn & B00111111;
    byte buttonAction = btn & B11000000;
    
    Serial.print("BUTTON_");
    Serial.write(buttonNumber + '0');
    Serial.print("_");

    if(buttonNumber == 1 and buttonAction == BUTTON_SHORT_RELEASE_IND){
        MFS.writeLeds(LED_ALL, ON);
        delay(1000);
    } else if(buttonNumber == 2 and buttonAction == BUTTON_SHORT_RELEASE_IND){
        MFS.writeLeds(LED_ALL, OFF);
        delay(1000);
    }
    
  }
}

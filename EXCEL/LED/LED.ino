char comando;
 
void setup() {
 
    Serial.begin(9600);
    pinMode(12,OUTPUT);
  
  }
 
void loop() {
 
    if (Serial.available()>0)
    {
        comando = Serial.read();
        
        switch (comando) 
        {
            case 'A':
                digitalWrite(12, HIGH);
            break;
            case 'B':
                digitalWrite(12, LOW);
            break;
    
        }
    }
}

// I2C Scanner
// Written by Nick Gammon
// Date: 20th April 2011

#include <Wire.h>

void setup()
{
  Serial.begin (9600);
  //  while (!Serial)
  {
  }

  Serial.println ();
  Serial.println ("I2C scanner. Procurando ...");
  byte count = 0;

  Wire.begin();
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {
      Serial.print ("Endereco I2C encontrado: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);
    }
  }
  Serial.print ("Encontrado ");
  Serial.print (count, DEC);
  Serial.println (" dispositivo(s).");
}

void loop() {}


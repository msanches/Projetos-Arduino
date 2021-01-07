#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte heart[8] = { 
  0b00000, // vetor de bytes correspondentes
  0b01010,  // ao desenho do coração
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};

void setup()
{
  lcd.begin(16, 2);
  int i, j, l;
  lcd.print("Quem e essa piranha");
  lcd.createChar(1, heart); // envia nosso character p/ o display
}

void loop()
{
  for (int i=0; i < 16; i++){  
    lcd.setCursor(i,1);
    lcd.write(1); // desenha o coração
    delay(500);
    
    lcd.setCursor(i,1);
    lcd.print(" "); // Após 0.5s apaga o coração, assim ele
    delay(500); // ficará piscando
  }
}

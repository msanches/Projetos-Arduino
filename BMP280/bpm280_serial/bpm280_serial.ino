#include <Adafruit_Sensor.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_BMP280.h> //INCLUSÃO DE BIBLIOTECA

Adafruit_BMP280 bmp; //OBJETO DO TIPO Adafruit_BMP280 (I2C)

void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
 //Verifica a conexão do sensor BMP280
  if (!bmp.begin())
  {
    Serial.println("Sensor não encontrado. Verifique as conexoes!");
    while (1);
  }
}

void loop(){
    Serial.print(F("Temperatura: ")); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(bmp.readTemperature()); //IMPRIME NO MONITOR SERIAL A TEMPERATURA
    Serial.println(" *C (Grau Celsius)"); //IMPRIME O TEXTO NO MONITOR SERIAL
    
    Serial.print(F("Pressão: ")); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(bmp.readPressure()); //IMPRIME NO MONITOR SERIAL A PRESSÃO
    Serial.println(" Pa (Pascal)"); //IMPRIME O TEXTO NO MONITOR SERIAL

    Serial.print(F("Altitude aprox.: ")); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(bmp.readAltitude(1013.25),0); //IMPRIME NO MONITOR SERIAL A ALTITUDE APROXIMADA
    Serial.println(" m (Metros)"); //IMPRIME O TEXTO NO MONITOR SERIAL
    
    Serial.println("-----------------------------------"); //IMPRIME UMA LINHA NO MONITOR SERIAL
    delay(2000); //INTERVALO DE 2 SEGUNDOS
}

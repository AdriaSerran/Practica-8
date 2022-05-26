#include <Arduino.h>
#define RXD2 16
#define TXD2 17

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
}

void loop() {
  while (Serial.available()) 
    {
      Serial2.print(char(Serial.read()));
    }
  while (Serial2.available()) 
    {
      Serial.print(char(Serial2.read()));
    }  

}
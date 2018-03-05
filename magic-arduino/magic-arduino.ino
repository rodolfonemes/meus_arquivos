#include <SoftwareSerial.h>

SoftwareSerial s(2,3);
int placar1=20;
int placar2=20;


void setup() {
  Serial.begin(9600);
  s.begin(9600);
  Serial.println("Inicio");
}

void loop() {

  while(s.available()) {
    char comando = s.read();
    Serial.println(comando);
    
    switch (comando) {
  case 'L':
    placar1 = placar1 + 1;
    Serial.print("Joagador 1 + ");
    Serial.println(placar1);
    break;
  case 'R':
   placar1 = placar1 - 1;
    Serial.print("Joagador 1 - ");
    Serial.println(placar1);
    break;
  
  case 'F':
    placar2 = placar2 + 1;
    Serial.print("Joagador 2 + ");
    Serial.println(placar2);
    break;
  
  case 'B':
   placar2 = placar2 - 1;
    Serial.print("Joagador 2 - ");
    Serial.println(placar2);
  break;
  
  default:
Serial.println(" ");
    }
  }

}

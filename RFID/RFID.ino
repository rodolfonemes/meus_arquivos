

#include <SoftwareSerial.h>
SoftwareSerial portaRfid(2, 3);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
portaRfid.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(portaRfid.available()){
  Serial.write (portaRfid.read());

}
}

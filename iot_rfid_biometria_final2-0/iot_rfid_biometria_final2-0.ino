#include <UIPEthernet.h>
#include <utility/logging.h>
#define SERIAL_RFID Serial1
#define SERIAL_FINGERPRINT Serial2

//Configurações do Ethernet Shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//byte ip[] = { 192,168,3,106  }; // ip que o arduino assumirá
//byte gateway[] = { 192,168,0,1 };  // ip do roteado
//byte subnet[] = { 255,255,255,0 };
EthernetServer server(8081); // Porta

int sensorPin = 13;
int sensorValue = 0;
int led = 12;

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac);
  server.begin();
  Serial.println(Ethernet.localIP());
  rfidSetup();
  fingerprintSetup();
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);
  pinMode(led, OUTPUT);
}

void loop() {
  sensorValue = digitalRead(sensorPin);
  
  EthernetClient client = server.available();
  
  //Serial.println(sensorValue);
  if (sensorValue == 1) {
    digitalWrite(led, HIGH);
    fingerprintLoop();
  } else {
    digitalWrite(led, LOW);
    rfidLoop();
  }
}

void enviar(String s) {
  EthernetClient client = server.available();
  if (client == true) {
    Serial.println("Enviando mesmo!");
    client.println(s);
  } else {
    Serial.println("Nenhum cliente encontrado!");
  }
}


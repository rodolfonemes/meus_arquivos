#include <SPI.h>
#include <UIPEthernet.h>
#include <utility/logging.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println(topic);
}

EthernetClient ethClient;
PubSubClient client("m10.cloudmqtt.com", 13038, callback, ethClient);

long lastReconnectAttempt = 0;
const char *cartaoCorreto = "";
#define TAMANHO_CARTAO 12

bool estavaLendoCartao = false;
bool lendoCartao = false;
char cartao[TAMANHO_CARTAO] = {};
int idxCartao = 0;
char c ;
SoftwareSerial portaRFID(6, 7); // RX, TX

boolean reconnect() {
  Serial.println("reconectando...");
  if (client.connect("CartaoIOT", "rodolfo", "rodolfo")) {
    Serial.println("conectado");
    client.publish("rfid",cartao);
    //client.subscribe("vaga/#");
  }
  return client.connected();
}

void setup()
{
  Serial.begin(9600);
  portaRFID.begin(9600);
  Serial.println("iniciando...");
  Ethernet.begin(mac);
  delay(1500);
  
  
  lastReconnectAttempt = 0;
}


void loop()
{
while (portaRFID.available()) {
    // após ler 12 caracteres, parar e resetar indice
    if (idxCartao == TAMANHO_CARTAO) {
      lendoCartao = false;
      idxCartao = 0;
    }

    c = portaRFID.read();
    if (c == 2) {
      lendoCartao = true;
    } else if (lendoCartao) {
      cartao[idxCartao] = c;
      idxCartao++;
    }
  }

  if (estavaLendoCartao && !lendoCartao) {
    // verificar se o cartao lido é o correto
    if (comparar(cartao, cartaoCorreto, TAMANHO_CARTAO)) {
      
    } else {
      client.publish("rfid",cartao);
      Serial.println(cartao);
     
    }
  }

  estavaLendoCartao = lendoCartao;


  
  if (!client.connected()) {
    long now = millis();
    if (now - lastReconnectAttempt > 5000) {
      Serial.println("reconectando2...");
      lastReconnectAttempt = now;
      
      if (reconnect()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
    client.loop();
  }

}

bool comparar(char *um, char *outro, int tamanho) {
  // percorrer caractere a caractere
  for (int i = 0; i < tamanho; i++) {
    // se algum for diferente
    if (um[i] != outro[i]) {
      // as duas 'strings' são diferentes
      return false;
    }
  }
  // senão são iguais
  return true;
}

#include <RestClient.h>
#include <UIPEthernet.h>
#include <SoftwareSerial.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x52 };

EthernetClient internet;
#define CONTENT_TYPE "application/json"
#define SERVER "caiocsampaio-001-site1.ftempurl.com"
#define ENDPOINT "/api/Auth/login/rfid"

RestClient client(SERVER, 80, internet);

const char *cartaoCorreto = "*";

#define TAMANHO_CARTAO 11

bool estavaLendoCartao = false;
bool lendoCartao = false;
char cartao[TAMANHO_CARTAO] = {};
int idxCartao = 0;
char c ;
int ledVermelho = 8;
int ledVerde = 9;

SoftwareSerial portaRFID(6, 7); // RX, TX
void setup() {
  client.setContentType(CONTENT_TYPE);
  Serial.begin(9600);
  portaRFID.begin(9600);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  if (Ethernet.begin(mac)) {
    Serial.println(F("Conectado via DHCP"));
    Serial.print(F("IP recebido:"));
    Serial.println(Ethernet.localIP());
  } else {
    Serial.println(F("DHCP falhou!"));
  }

}

void loop() {
  // enquanto houver algum caractere vindo do RFID
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
    //if (comparar(cartao, cartaoCorreto, TAMANHO_CARTAO)) {
    Serial.print(F("cartao lido: "));
    Serial.println(cartao);
    enviarCodigo();
  }

  estavaLendoCartao = lendoCartao;
}

void enviarCodigo() {
  // Montando o JSON via concatenação
  String body = "{\"rfId\":\"";
  body += cartao;
  body += "\"}";

  Serial.println(body);

  // A biblioteca retorna o código de status da requisição HTTP
  int statusCode = client.post(
                     ENDPOINT,
                     // utilizamos o método String#c_str() para obter um *char a partir da
                     // classe String do arduino
                     // https://www.arduino.cc/reference/en/language/variables/data-types/string/functions/c_str/
                     body.c_str(),
                     // Para ignorar o resultado podemos passar um pointer para NULL e tamanho
                     // 0:
                     NULL, 0);

  Serial.print(F("Codigo de resposta: "));
  Serial.println(statusCode);
}

// Funcao que retorna se 2 arrays de chars são iguais
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

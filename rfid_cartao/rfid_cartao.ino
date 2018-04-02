#include <SoftwareSerial.h>

const char *cartaoCorreto = "";

#define TAMANHO_CARTAO 12

bool estavaLendoCartao = false;
bool lendoCartao = false;
char cartao[TAMANHO_CARTAO] = {};
int idxCartao = 0;
char c ;
int ledVermelho = 6;
int ledVerde = 7;

// conectar RX com TX do RFID,
// pino TX da SoftwareSerial não é utilizado
//SoftwareSerial portaRFID(19, 18); // RX, TX

void setup() {

  Serial.begin(9600);
  Serial1.begin(9600);
 // portaRFID.begin(9600);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
}

void loop() {
  // enquanto houver algum caractere vindo do RFID
  while (Serial1.available()) {
    // após ler 12 caracteres, parar e resetar indice
    if (idxCartao == TAMANHO_CARTAO) {
      lendoCartao = false;
      idxCartao = 0;
    }

    c = Serial1.read();
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
      // tocar buzzer
      Serial.print("cartao lido: ");
      Serial.println(cartao);
    }
  }

  estavaLendoCartao = lendoCartao;
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

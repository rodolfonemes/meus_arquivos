#define TAMANHO_CARTAO 12

bool estavaLendoCartao = false;
bool lendoCartao = false;
char cartao[TAMANHO_CARTAO] = {};
int idxCartao = 0;

void rfidSetup() {
  SERIAL_RFID.begin(9600);
}

void rfidLoop() {
  while (SERIAL_RFID.available()) {
    // após ler 12 caracteres, parar e resetar indice
    if (idxCartao == TAMANHO_CARTAO) {
      lendoCartao = false;
      idxCartao = 0;
    }

    char c = SERIAL_RFID.read();
    if (c == 2) {
      lendoCartao = true;
    } else if (lendoCartao) {
      cartao[idxCartao] = c;
      idxCartao++;
    }

  }
  if (estavaLendoCartao && !lendoCartao) { // se terminou de ler algum cartao
    String s(cartao);
    Serial.print("Enviando cartao: ");
    Serial.println(s);
    enviar(s);
  }

  estavaLendoCartao = lendoCartao;
}

//bool comparar(char *um, char *outro, int tamanho) {
//  // percorrer caractere a caractere
//  for (int i = 0; i < tamanho; i++) {
//    // se algum for diferente
//    if (um[i] != outro[i]) {
//      // as duas 'strings' são diferentes
//      return false;
//    }
//  }
//  // senão são iguais
//  return true;
//}


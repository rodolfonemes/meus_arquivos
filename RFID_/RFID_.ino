#include <SoftwareSerial.h>
#include <Servo.h>

const char *cartaoCorreto = "410033F08507";

#define TAMANHO_CARTAO 12

bool estavaLendoCartao = false;
bool lendoCartao = false;
char cartao[TAMANHO_CARTAO] = {};
int idxCartao = 0;
Servo servo;
//int pos = 0;
int buzzer = 6;
int luz = 12;
char c ;

// conectar RX com TX do RFID,
// pino TX da SoftwareSerial não é utilizado
SoftwareSerial portaRFID(6, 7); // RX, TX
void setup() {

  Serial.begin(9600);
  portaRFID.begin(9600);
  //servo.attach(12);
  //servo.write(pos);
  pinMode(buzzer, OUTPUT);
  pinMode(luz, OUTPUT);
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
    if (comparar(cartao, cartaoCorreto, TAMANHO_CARTAO)) {
      // abrir/fechar servo (toggle)
      Serial.println("Abrir portao");
      Serial.println(cartao);
      digitalWrite(luz, HIGH);
      //servo.write(90);
      delay(2000);
      //servo.write(90);
      digitalWrite(luz, LOW);
    } else {
      // tocar buzzer
      Serial.println("403");
      Serial.println(cartao);
      tone(buzzer, 10000);
      delay(2000);
      noTone(buzzer);
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

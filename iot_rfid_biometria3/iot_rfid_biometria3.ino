#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#define TAMANHO_CARTAO 12

char *cartaoCorreto = "";
bool estavaLendoCartao = false;
bool lendoCartao = false;
char cartao[TAMANHO_CARTAO] = {};
int idxCartao = 0;

SoftwareSerial SERIAL_RFID(6, 7);
SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

int sensorPin = 13;
int sensorValue = 0;
int led = 12;

int getFingerprintIDez();

void setup() {
  Serial.begin(9600);
  SERIAL_RFID.begin(9600);
  finger.begin(57600);

  //fingerprintSetup();
  //rfidSetup();
  pinMode(led, OUTPUT);

  if (finger.verifyPassword()) {
    Serial.println("OK");
  } else {
    Serial.println("999");
    while (1);
  }
  //Serial.println("Esperando Dedo para Verificar");
}

void loop() {

  sensorValue = digitalRead(sensorPin);

  if (sensorValue == 0) {
    digitalWrite(led, HIGH);
    //fingerprintLoop();
    getFingerprintIDez();
  } else {
    digitalWrite(led, LOW);
    //rfidLoop();
    while (SERIAL_RFID.available()) {
              Serial.print("teste ");

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
    if (estavaLendoCartao && !lendoCartao) {
      // verificar se o cartao lido é o correto
      if (comparar(cartao, cartaoCorreto, TAMANHO_CARTAO)) {

      } else {
        Serial.print("cartao lido: ");
        Serial.println(cartao);
      }
    }

    estavaLendoCartao = lendoCartao;

  }
}

int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  //  digitalWrite(12, LOW);
  //  digitalWrite(11, HIGH);
  //  delay(1000);
  //  digitalWrite(11, LOW);
  //  delay(1000);
  //  digitalWrite(12, HIGH);
  //Serial.print("ID # Encontrado");
  Serial.println(finger.fingerID);
  //Serial.print(" com precisao de ");
  //Serial.println(finger.confidence);
  return finger.fingerID;
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

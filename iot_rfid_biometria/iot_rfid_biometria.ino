// Programa para teste de funcionamento do Leitor Biometrico
// Traduzido e adaptado por Usinainfo

#define SERIAL_FINGERPRINT Serial2
#define SERIAL_RFID Serial1

#define ESTADO_LER_FINGERPRINT 0
#define ESTADO_LER_RFID 1
#define INTERVALO_TROCA 6000
int estado = ESTADO_LER_FINGERPRINT;

unsigned long ultimaTrocaDeEstado = 0;

void setup() {
  SERIAL_FINGERPRINT.begin(57600);
  SERIAL_RFID.begin(9600);
  
  fingerprintSetup();
}

void loop() {
  switch (estado) {
    case ESTADO_LER_FINGERPRINT:
      fingerprintLoop();
      break;
    case ESTADO_LER_RFID:
      rfidLoop();
      break;
  }
  if(millis() - ultimaTrocaDeEstado > INTERVALO_TROCA) {
    estado = 1 - estado;
    ultimaTrocaDeEstado = millis();
  }
}

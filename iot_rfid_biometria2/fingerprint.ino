#include <Adafruit_Fingerprint.h>

int getFingerprintIDez();

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&SERIAL_FINGERPRINT);

void fingerprintSetup()  {  
  Serial.begin(9600);
  //Serial.println("Iniciando Leitor Biometrico");

  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("OK");
  } else {
    Serial.println("999");
    while (1);
  }
  //Serial.println("Esperando Dedo para Verificar");
}

void fingerprintLoop()                   
{
  getFingerprintIDez();
}
//uint8_t getFingerprintID() {
//  uint8_t p = finger.getImage();
//  switch (p) {
//    case FINGERPRINT_OK:
//      Serial.println("Imagem Capturada");
//      break;
//    case FINGERPRINT_NOFINGER:
//      Serial.println("Dedo nao Localizado");
//      return p;
//    case FINGERPRINT_PACKETRECIEVEERR:
//      Serial.println("Erro ao se comunicar");
//      return p;
//    case FINGERPRINT_IMAGEFAIL:
//      Serial.println("Erro ao Capturar");
//      return p;
//    default:
//      Serial.println("Erro desconhecido");
//      return p;
//  }
//
//  p = finger.image2Tz();
//  switch (p) {
//    case FINGERPRINT_OK:
//      Serial.println("Imagem Convertida");
//      break;
//    case FINGERPRINT_IMAGEMESS:
//      Serial.println("Imagem muito confusa");
//      return p;
//    case FINGERPRINT_PACKETRECIEVEERR:
//      Serial.println("Erro ao se comunicar");
//      return p;
//    case FINGERPRINT_FEATUREFAIL:
//      Serial.println("Impossivel localizar Digital");
//      return p;
//    case FINGERPRINT_INVALIDIMAGE:
//      Serial.println("Impossivel Localizar Digital");
//      return p;
//    default:
//      Serial.println("Erro Desconhecido");
//      return p;
//  }
//  
//  p = finger.fingerFastSearch();
//  if (p == FINGERPRINT_OK) {
//    Serial.println("Digital Encontrada");
//  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
//    Serial.println("Erro ao se comunicar");
//    return p;
//  } else if (p == FINGERPRINT_NOTFOUND) {
//    Serial.println("Digital Desconhecida");
//    return p;
//  } else {
//    Serial.println("Erro Desconhecido");
//    return p;
//  }   
//  
//  Serial.print("ID # Encontrado"); 
//  Serial.print(finger.fingerID); 
//  Serial.print(" com precisao de "); 
//  Serial.println(finger.confidence); 
//}
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  {
    //Serial.println("erro1"); 
    return -1;
    }

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  {
    //Serial.println("erro2"); 
    return -1;
    }

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  {
    Serial.println("digital nao localizada"); 
    return -1;
    }
  
//  digitalWrite(12, LOW);
//  digitalWrite(11, HIGH);
//  delay(1000);
//  digitalWrite(11, LOW);
//  delay(1000);
//  digitalWrite(12, HIGH);
  //Serial.print("ID # Encontrado"); 
  Serial.print("00000");
  Serial.println(finger.fingerID);
  
  //Serial.print(" com precisao de "); 
  //Serial.println(finger.confidence);
  return finger.fingerID; 
}

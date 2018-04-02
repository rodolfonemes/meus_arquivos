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
  Serial.print("00000");
  Serial.println(finger.fingerID); 
  //Serial.print(" com precisao de "); 
  //Serial.println(finger.confidence);
  return finger.fingerID; 
}

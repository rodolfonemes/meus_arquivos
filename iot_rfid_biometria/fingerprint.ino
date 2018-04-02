

#include <Adafruit_Fingerprint.h>
int getFingerprintIDez();

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&SERIAL_FINGERPRINT);

void fingerprintSetup() {

  if (finger.verifyPassword()) {
    Serial.println("OK");
  } else {
    Serial.println("999");
  }
}
void fingerprintLoop() {
  unsigned long start = micros();
  int fingerId = getFingerprintIDez();
  unsigned long finish = micros();

  // Serial.print("Demorou:");
  // Serial.println(finish - start);
  if(fingerId != -1) {
    Serial.println(fingerId);
  }
}
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  return finger.fingerID;
}

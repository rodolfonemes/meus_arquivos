#define SERIAL_RFID Serial1
#define SERIAL_FINGERPRINT Serial2

int sensorPin = 13;
int sensorValue = 0;
int led = 12;


void setup() {
  Serial.begin(9600);
  rfidSetup();
  fingerprintSetup();
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);
  pinMode(led, OUTPUT);
}

void loop() {


  sensorValue = digitalRead(sensorPin);
  //Serial.println(sensorValue);
  if (sensorValue == 1) {
    digitalWrite(led, HIGH);
    fingerprintLoop();
  } else {
    digitalWrite(led, LOW);
    rfidLoop();
  }
}

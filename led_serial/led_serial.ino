#include <LiquidCrystal.h>
const int LED = 13;
const int SOM = 11;
String inData;
String inDat;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600);    //configura comunicação serial com 9600 bps
  pinMode(LED, OUTPUT);  //configura pino do led como saída
  lcd.begin(16, 2);
  lcd.print("AGUARNDO COMANDO!!!!!!!");
}

void loop() {

while (Serial.available() > 0)
    {
        char recieved = Serial.read();
        inData += recieved;
        
                // Process message when new line character is recieved
        if (recieved == '\n')
        {
            Serial.print("Arduino Received: ");
            Serial.print(inData);

            if (inData == "TEXTO\n"){
                 lcd.begin(16, 2);
                 lcd.print(inData);
                 }
            
            if(inData == "ACENDER\n"){ // DON'T forget to add "\n" at the end of the string.
              digitalWrite(LED,HIGH);
              lcd.begin(16, 2);
              lcd.print("LED ACESSO!!!!!!!");
            }
            if (inData == "APAGAR\n") {
   
            digitalWrite(LED,LOW);
            lcd.begin(16, 2);
            lcd.print("LED APAGADO!!!!!!!");
           }

              if (inData == "PISCAR\n"){
             lcd.begin(16, 2);
            lcd.print("LED PISCANDO!!!!!!!");
              digitalWrite(LED,HIGH);
                 delay(1000);
                 digitalWrite(LED,LOW);
                 delay(1000);
                 digitalWrite(LED,HIGH);
                 delay(1000);
                 digitalWrite(LED,LOW);
                 delay(1000);
                 digitalWrite(LED,HIGH);
                 delay(1000);
                 digitalWrite(LED,LOW);
                 delay(1000);
                 digitalWrite(LED,HIGH);
                 delay(1000);
                 digitalWrite(LED,LOW);
                 delay(1000);
                
              }
                  if (inData == "TESTE\n") {
                     digitalWrite(LED, !digitalRead(LED));
                             
                             }

                             if (inData == "SOM\n") {
                       lcd.begin(16, 2);
                       lcd.print("SOM EM TESTE!!!!!!!");
                       int frequencia;
                    frequencia=440; // frequência correspondente a notá Lá
                    tone(SOM,frequencia);
                    delay(500);
                    noTone(SOM);
                    delay(500);
                             }
              if (inData == "LCD\n") {
            lcd.setCursor(0, 1);
            lcd.print(millis() / 1000);
           }
          inData = ""; // Clear recieved buffer
        }
    }
             

        
    }

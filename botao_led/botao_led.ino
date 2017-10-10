int pinLed = 12;
int pinBotao = 11;
int estadoBotao = LOW;

void setup() {
 
}

void loop() {

estadoBotao = digitalRead (pinBotao); 
  
  if (estadoBotao == HIGH){
    digitalWrite (pinLed, HIGH);
    } 
else{
  digitalWrite (pinLed, LOW);
  }
}

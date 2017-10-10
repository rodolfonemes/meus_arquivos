int pinoPonteciomentro =A0;
int valorPonteciomentro =A0;
void setup()
{
 Serial.begin(9600); 
}

void loop()
{
  valorPonteciomentro = analogRead(pinoPonteciomentro);
  Serial.println(valorPonteciomentro);
  digitalWrite(led, HIGH);
}


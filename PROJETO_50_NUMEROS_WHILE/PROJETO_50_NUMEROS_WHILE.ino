int contador = 1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.print("iniciando...");

while ( contador <= 50 )
{
  Serial.print("contador");
  Serial.println(contador);
  contador++;
}
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(contador);
}


int r = 13;
int y = 12;
int g = 11;

void setup() {
 
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  digitalWrite(r , HIGH);  
  delay(1000);                      

  digitalWrite(y , HIGH); 
  delay(1000);

  digitalWrite(g , HIGH); 
  delay(5000);
  
  digitalWrite(r , LOW);  
  delay(1000);
               
  digitalWrite(y , LOW);   
  delay(1000);

  digitalWrite(g , LOW);   
  delay(1000);  
  
}


int a = 13;
int b = 12;
int c = 11;
int d = 10;
int e = 9;
int f = 8;
int g = 7;
int h = 6;
int i = 5;
int j = 4;

void setup() {
 
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  pinMode(i, OUTPUT);
  pinMode(j, OUTPUT);

}

void loop() {

  //vai
  
  digitalWrite(a , HIGH);  
  delay(1000);                      

  digitalWrite(b , HIGH); 
  delay(1000);

  digitalWrite(c , HIGH); 
  delay(1000);

  digitalWrite(d , HIGH);  
  delay(1000);                      

  digitalWrite(e , HIGH); 
  delay(1000);

  digitalWrite(f , HIGH); 
  delay(1000);
  
  digitalWrite(g , HIGH);  
  delay(1000);                      

  digitalWrite(h , HIGH); 
  delay(1000);

  digitalWrite(i , HIGH); 
  delay(1000);
 
  digitalWrite(j , HIGH);  
  delay(2000);                      
 
  digitalWrite(a , LOW);  
  delay(1000);
               
  digitalWrite(b , LOW);   
  delay(1000);

  digitalWrite(c , LOW);   
  delay(1000);  

  digitalWrite(d , LOW);  
  delay(1000);
               
  digitalWrite(e , LOW);   
  delay(1000);

  digitalWrite(f , LOW);   
  delay(1000);  

  digitalWrite(g , LOW);  
  delay(1000);
               
  digitalWrite(h , LOW);   
  delay(1000);

  digitalWrite(i , LOW);   
  delay(1000);  

  digitalWrite(j , LOW);  
  delay(1000);

  //volta
  
  digitalWrite(j , HIGH);  
  delay(1000);                      

  digitalWrite(i , HIGH); 
  delay(1000);

  digitalWrite(h , HIGH); 
  delay(1000);

  digitalWrite(g , HIGH);  
  delay(1000);                      

  digitalWrite(f , HIGH); 
  delay(1000);

  digitalWrite(e , HIGH); 
  delay(1000);
  
  digitalWrite(d , HIGH);  
  delay(1000);                      

  digitalWrite(c , HIGH); 
  delay(1000);

  digitalWrite(b , HIGH); 
  delay(1000);
 
  digitalWrite(a , HIGH);  
  delay(2000);                      
 
  digitalWrite(j , LOW);  
  delay(1000);
               
  digitalWrite(i , LOW);   
  delay(1000);

  digitalWrite(h , LOW);   
  delay(1000);  

  digitalWrite(g , LOW);  
  delay(1000);
               
  digitalWrite(f , LOW);   
  delay(1000);

  digitalWrite(e , LOW);   
  delay(1000);  

  digitalWrite(d , LOW);  
  delay(1000);
               
  digitalWrite(c , LOW);   
  delay(1000);

  digitalWrite(b , LOW);   
  delay(1000);  

  digitalWrite(a , LOW);  
  delay(1000);

}

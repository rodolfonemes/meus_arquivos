String inData;

void setup() {
  // put your setup code here, to run once:
 
 Serial.begin(9600);
 Serial.println("Serial conection started, waiting for instructions...");
}

void loop() {
  // put your main code here, to run repeatedly:

 while (Serial.available() > 0)
    {
        char recieved = Serial.read();
        inData += recieved; 

    switch (inData) {
    case "APAGAR":
      digitalWrite(LED,LOW
      break;
    case "ACENDER":
      digitalWrite(LED,HIGH);
      break;
    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
  }
    }
    }  
        
        
        
        
        
        // Process message when new line character is recieved
//        if (recieved == '\n')
//        {
//            Serial.print("Arduino Received: ");
//            Serial.print(inData);
//
//            // You can put some if and else here to process the message juste like that:
//
//            if(inData == "+++\n"){ // DON'T forget to add "\n" at the end of the string.
//              Serial.println("OK. Press h for help.");
//            }   
//
//
//            inData = ""; // Clear recieved buffer
//        }


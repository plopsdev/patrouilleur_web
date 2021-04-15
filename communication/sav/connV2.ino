

void setup(){
 
  Serial.begin(9600);
}

void loop(){
  char message = get_serial_command_from_pi();
  
  if (message == 'a')// 97 = 'a' dans le message envoyé en dascii 
  //if(message >= 1) // permet de tester et de voir uniquement les caractère envoyé
  {
    Serial.print(message);   
    Serial.print(message);
    Serial.println(message); 
  }
  if (message == 'b') // 98 = 'b' dans le message envoyé en dascii 
  {
    Serial.print(message);  
    Serial.println(message);  
  }
}


char get_serial_command_from_pi(){
  char byteMessage = 0;
  if(Serial.available()>0){
    byteMessage = Serial.read();
    }
  return byteMessage;
}

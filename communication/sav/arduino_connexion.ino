


void setup(){
 
  Serial.begin(9600);
}

void loop(){
  char message = get_serial_command_from_pi();
  
  if (message == 97)// 97 = 'a' dans le message envoyé en dascii 
  //if(message >= 1) // permet de tester et de voir uniquement les caractère envoyé
  {
    Serial.println(message);    
  }
  if (message == 98) // 98 = 'b' dans le message envoyé en dascii 
  {
    Serial.println(message);    
  }
}


int get_serial_command_from_pi(){
  char byteMessage = 0;
  if(Serial.available()>0){
    byteMessage = Serial.read();
    }
  return byteMessage;
}

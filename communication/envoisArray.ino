const int sizeArr = 25;
int arrayrobot[sizeArr];

void setup() {
    Serial.begin(9600);
    Serial.println("Enter data ");
    Serial.println();
}

//============

void loop() {
  fillArray(arrayrobot);
    for(int i=0; i <sizeArr; i++){
        if(arrayrobot[i] != 0){
          Serial.print(arrayrobot[i]);      
          Serial.print(" ; ");            
        }
    }
     Serial.println(); 
     delay(1000);
}

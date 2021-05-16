#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);

const byte address[6] = "00001";
int joyPosV=512;
int joyPosH=512;
uint8_t motorControl[3];
void setup() {
  motorControl[2]=1;//motor set forward
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
  Serial.begin(115200);
}

void loop() {
  joyPosV=analogRead(A0);
  joyPosH=analogRead(A1);
  /*Serial.println("VERT");
  Serial.println(joyPosV);
  Serial.println("HOR");
  Serial.println(joyPosH);*/
  
  
  if(joyPosV>460 &&joyPosV<550 && joyPosH>460 &&joyPosH<550 ){
    motorControl[1]=0; // all stoped
    motorControl[2]=0;
    motorControl[0]=2;
    //Serial.println("Stop");
    }
   if(joyPosV>=550){
    motorControl[1]=map(joyPosV,550,1023,0,255); 
    motorControl[2]=map(joyPosV,550,1023,0,255);
    motorControl[0]=1;//forward

    }
    if(joyPosV<=460){
    motorControl[1]=map(joyPosV,460,0,0,255); 
    motorControl[2]=map(joyPosV,460,0,0,255);
    motorControl[0]=0;//backward

    }
    if(joyPosH>=550){
    motorControl[1]=map(joyPosH,550,1023,0,255);
    motorControl[2]=0;
    motorControl[0]=0;//right

    }
    if(joyPosH<=460){
    motorControl[1]=0;
    motorControl[2]=map(joyPosH,460,0,0,255);
    motorControl[0]=0;//left

    }

  radio.write(&motorControl, sizeof(motorControl));
  delay(5);
}

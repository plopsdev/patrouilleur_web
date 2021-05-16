#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);

const byte address[6] = "00001";
uint8_t motorControl[3];

void setup() {
  // put your setup code here, to run once:

  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  Serial.begin(115200);
}

void loop() {
  char text[32] = "";
  
 if (radio.available()) {
    while(radio.available()){
      radio.read(&motorControl,sizeof(motorControl));
     Serial.println(motorControl[0]);
      Serial.println(motorControl[1]);
      Serial.println(motorControl[2]);
      Serial.println("###########");

    }
 }
 }

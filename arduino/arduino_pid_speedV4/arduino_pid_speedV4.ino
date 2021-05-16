#include <PinChangeInt.h>

/*
  Motor - PID speed control
  (1) Receive command from Visual Studio (via COM1): set_speed, kP, kI, kD
  (2) Control motor speed through PWM (PWM is base on PID calculation)
  (3) Send pv_speed to Visual Studio -> show in graph
  

 */
boolean stringComplete = false;  // whether the string is complete
boolean motor_start = false;
String mySt = "";
char myChar;
const byte pin_aG = 2;   //for encoder pulse A
const byte pin_bG = 12;   //for encoder pulse B
const byte pin_aD = 3;   //for encoder pulse A
const byte pin_bD = 4;   //for encoder pulse B

const byte pin_fwdG = 5; //for H-bridge: run motor forward
const byte pin_bwdG = 6; //for H-bridge: run motor backward

const byte pin_fwdD = 9; //for H-bridge: run motor forward
const byte pin_bwdD = 10; //for H-bridge: run motor backward

double encoderAG = 0;
double encoderBG = 0;
double encoderAD = 0;
double encoderBD = 0;

double set_speedG = 0;
double set_speedD = 0;


double pv_speedG = 0;
double e_speedG = 0; //error of speed = set_speed - pv_speed
double e_speed_preG = 0;  //last error of speed
double e_speed_sumG = 0;  //sum error of speed
double pwm_pulseG = 0;     //this value is 0~255

double pv_speedD = 0;
double e_speedD = 0; //error of speed = set_speed - pv_speed
double e_speed_preD = 0;  //last error of speed
double e_speed_sumD = 0;  //sum error of speed
double pwm_pulseD = 0;     //this value is 0~255

double kp = 0.015; //0.015 - 0.01 -0.01 for G motor 
double ki = 0.01;//
double kd = 0.01; 

int i=0;
int interval=100;
unsigned long previousMillis=0;
unsigned long previousMillis1=0;
String text_speeds;


void setup() {
  pinMode(pin_aG,INPUT_PULLUP);
  pinMode(pin_bG,INPUT_PULLUP);
  pinMode(pin_aD,INPUT_PULLUP);
  pinMode(pin_bD,INPUT_PULLUP);
  
  pinMode(pin_fwdD,OUTPUT);
  pinMode(pin_bwdD,OUTPUT);
  pinMode(pin_fwdG,OUTPUT);
  pinMode(pin_bwdG,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pin_aG), detect_aG,CHANGE);
  attachInterrupt(digitalPinToInterrupt(pin_aD), detect_aD, CHANGE);
  attachPinChangeInterrupt(pin_bG, detect_bG,CHANGE);
  attachPinChangeInterrupt(pin_bD, detect_bD, CHANGE);
  
    Serial.begin(9600);


 

  digitalWrite(pin_fwdG,0);  //stop motor
  digitalWrite(pin_bwdG,0);  //stop motor
  digitalWrite(pin_fwdD,0);  //stop motor
  digitalWrite(pin_bwdD,0);  //stop motor
}

void loop() {

 if (stringComplete) {
    // clear the string when COM receiving is completed
    mySt = "";  //note: in code below, mySt will not become blank, mySt is blank until '\n' is received
    stringComplete = false;
  }

  //receive command from Visual Studio
  if (mySt.substring(0,8) == "vs_start"){
    motor_start = true;
  }
  if (mySt.substring(0,7) == "vs_stop"){
     digitalWrite(pin_fwdD,0);
     digitalWrite(pin_bwdD,0);
     digitalWrite(pin_fwdG,0);
     digitalWrite(pin_bwdG,0);   
    
    //stop motor
    motor_start = false;
  }
  if (mySt.substring(0,9) == "vs_speedG"){
    set_speedG = mySt.substring(9,mySt.length()).toFloat();  //get string after set_speed
  }
  if (mySt.substring(0,9) == "vs_speedD"){
    set_speedD = mySt.substring(9,mySt.length()).toFloat();  //get string after set_speed
  }
  if (mySt.substring(0,5) == "vs_kp"){
    kp = mySt.substring(5,mySt.length()).toFloat(); //get string after vs_kp
  }
  if (mySt.substring(0,5) == "vs_ki"){
    ki = mySt.substring(5,mySt.length()).toFloat(); //get string after vs_ki
  }
  if (mySt.substring(0,5) == "vs_kd"){
    kd = mySt.substring(5,mySt.length()).toFloat(); //get string after vs_kd
  }  

//CHOOSE YOUR STYLE RUN
//set_speed=1000;
//motor_start = true;
bool back = false;

 unsigned long currentMillis=millis();
  if ( currentMillis-previousMillis>= interval){ // boucle appellé toutes les 100ms
       previousMillis=currentMillis;

  pv_speedG = ((encoderAG+encoderBG)*600)/64;  //calculate motor speed[rpm] 
 // Serial.println(pv_speedG);
  encoderAG=0;
  encoderBG=0;
  
  pv_speedD = ((encoderAD+encoderBD)*600)/64;  //calculate motor speed[rpm] 
  encoderAD=0;
  encoderBD=0;// 64 ticks -- 1 tr
             // x ticks -- 0.1 sec
             // x ticks --  0.1/60 min
             // x ticks*600 -- 1min
             // x ticks*600 /64 pour avoir les tr/min avant la reduction
  //print out speed
  unsigned long currentMillis1=millis();
  if ( currentMillis1-previousMillis1>= 55){ // boucle appellé toutes les 100ms
       previousMillis1=currentMillis;

  text_speeds.concat(pv_speedG);
  text_speeds.concat(":");
  text_speeds.concat(pv_speedD);
  text_speeds.concat(":");
  
    
    Serial.println(text_speeds);  
    text_speeds="";
    //Print speed (rpm) value to Visual Studio
  }   
    

  //PID program
  if (motor_start){
    e_speedG= set_speedG - pv_speedG;
    pwm_pulseG = e_speedG*kp + e_speed_sumG*ki + (e_speedG - e_speed_preG)*kd;
    e_speed_preG = e_speedG;  //save last (previous) error
    e_speed_sumG += e_speedG; //sum of error

    e_speedD= set_speedD - pv_speedD;
    pwm_pulseD = e_speedD*kp + e_speed_sumD*ki + (e_speedD - e_speed_preD)*kd;
    e_speed_preD = e_speedD;  //save last (previous) error
    e_speed_sumD += e_speedD; //sum of error
 
  }
  else{
    e_speedD = 0;
    e_speed_preD = 0;
    e_speed_sumD = 0;
    pwm_pulseD = 0;
    
    e_speedG = 0;
    e_speed_preG = 0;
    e_speed_sumG = 0;
    pwm_pulseG = 0;
  }
  
byte pin_runG =5;
byte pin_runD=10;
// check if go forward or backward
 if(back==true){
 pin_runG = pin_bwdG; //for H-bridge: run motor forward
 pin_runD = pin_bwdD;
 }
else{
  pin_runG=pin_fwdG;
  pin_runD=pin_fwdD;
  }
  
 // RUN MOTOR D
  if (pwm_pulseD <255 & pwm_pulseD >0){
    analogWrite(pin_runD,pwm_pulseD);  //set motor speed
  }
  else{
    if(pwm_pulseD>255){
      analogWrite(pin_runD,255);
    }
    else{
      analogWrite(pin_runD,0);
    }
  }
  
  // RUN MOTOR G
  if (pwm_pulseG <255 & pwm_pulseG >0){
    analogWrite(pin_runG,pwm_pulseG);  //set motor speed  
  }
  else{
    if (pwm_pulseG>255){
      analogWrite(pin_runG,255);
    }
    else{
      analogWrite(pin_runG,0);
    }
  }
  
 } 
  
  
}


void detect_aG() {
  encoderAG+=1; //increasing encoder at new pulse
}
void detect_bG() {
  encoderBG+=1; //increasing encoder at new pulse
}
void detect_aD() {
  encoderAD+=1; //increasing encoder at new pulse
}
void detect_bD() {
  encoderBD+=1; //increasing encoder at new pulse
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    if (inChar != '\n') {
      mySt += inChar;
    }
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
 

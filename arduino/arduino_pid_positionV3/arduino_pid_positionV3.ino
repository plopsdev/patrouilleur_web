// PID motor position control.
// Thanks to Brett Beauregard for his nice PID library http://brettbeauregard.com/blog/2011/04/improving-the-beginners-pid-introduction/

#include <PinChangeInt.h>


#define encodPinAG      2                       // Quadrature encoder A pin
#define encodPinBG      7                       // Quadrature encoder B pin
#define encodPinAD      3                      //for encoder pulse A
#define encodPinBD      8                      //for encoder pulse B

const byte pin_fwdG = 5; //for H-bridge: run motor forward
const byte pin_bwdG = 6; //for H-bridge: run motor backward

const byte pin_fwdD = 9; //for H-bridge: run motor forward
const byte pin_bwdD = 10; //for H-bridge: run motor backward

volatile long encoderPosG = 0;
volatile long encoderPosD = 0;

unsigned long previousMillis=0;
unsigned long previousMillis1=0;
String text_speeds;
String mySt = "";
char myChar;
boolean stringComplete = false;  // whether the string is complete
boolean motor_start = false;

double set_pos=0;

double pv_posG = 0;
double set_posG = 0;
double e_posG = 0; //error of speed = set_speed - pv_speed
double e_pos_preG = 0;  //last error of speed
double e_pos_sumG = 0;  //sum error of speed
double pwm_pulseG = 0;     //this value is 0~255

double pv_posD = 0;
double set_posD = 0;
double e_posD = 0; //error of speed = set_speed - pv_speed
double e_pos_preD = 0;  //last error of speed
double e_pos_sumD = 0;  //sum error of speed
double pwm_pulseD = 0;     //this value is 0~255

double kp = 0.5 , ki =0.1 , kd = 0.1;  //ki et kd petits 3.5/0.001/0.001     // modify for optimal performance
double interval=10;

void setup() {
  pinMode(encodPinAG, INPUT_PULLUP);                  // quadrature encoder input A
  pinMode(encodPinBG, INPUT_PULLUP);                  // quadrature encoder input B
  pinMode(encodPinAD, INPUT_PULLUP);                  // quadrature encoder input A
  pinMode(encodPinBD, INPUT_PULLUP);
  pinMode(pin_fwdG,OUTPUT);
  pinMode(pin_bwdG,OUTPUT);
  pinMode(pin_fwdD,OUTPUT);
  pinMode(pin_bwdD,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encodPinAG), encoderG, FALLING);               // update encoder position
  attachInterrupt(digitalPinToInterrupt(encodPinAD), encoderD, FALLING);
  //TCCR0B = TCCR0B & 0b11111000 | 1;                   // set 8KHz PWM to prevent motor noise

  Serial.begin (9600);                              // for debugging
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
    digitalWrite(pin_fwdG,0);
    digitalWrite(pin_bwdG,0);      //stop motor
    digitalWrite(pin_fwdD,0);
    digitalWrite(pin_bwdD,0); 
    motor_start = false;
  }
  if (mySt.substring(0,10) == "vs_set_pos"){
    set_pos = (mySt.substring(10,mySt.length()).toFloat());  //get string after set_pos
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
  unsigned long currentMillis1=millis();
  if ( currentMillis1-previousMillis1>=53){ // boucle appellé toutes les 100ms
       previousMillis1=currentMillis1; 

  text_speeds.concat(encoderPosG);
  text_speeds.concat(":");
  text_speeds.concat(encoderPosD);
  text_speeds.concat(":");
  if (Serial.available() <= 0) {
    Serial.println(text_speeds);  
    text_speeds=""; 
    //Print speed (rpm) value to Visual Studio
    }

  }
  unsigned long currentMillis=millis();
  if ( currentMillis-previousMillis>=interval){ // boucle appellé toutes les 10ms
       previousMillis=currentMillis;                        // modify to fit motor and encoder characteristics, potmeter connected to A0
                                                        // data from encoder                                    
   e_posG = set_pos-encoderPosG;
   e_posD= set_pos- encoderPosD;

   calcPID_D(e_posD);
   calcPID_G(e_posG);
   
}
}
void calcPID_G(double e_posG){
  if(e_posG<5&&  e_posG>=0){
    e_posG = 0;
    e_pos_preG = 0;
    e_pos_sumG = 0;
    pwm_pulseG = 0;
   }
   else if(e_posG>-5 &&  e_posG<=0){
    e_posG = 0;
    e_pos_preG = 0;
    e_pos_sumG = 0;
    pwm_pulseG = 0;
   }
    pwm_pulseG = e_posG*kp + ki*e_pos_sumG + ((e_posG - e_pos_preG)/interval)*kd;
     e_pos_sumG += e_posG*interval; //sum of error
     if(e_pos_sumG>255.00)e_pos_sumG=255.00;
     if(e_pos_sumG<-255.00)e_pos_sumG=-255.00;
    e_pos_preG = encoderPosG;  //save last (previous) error
   
   if(motor_start==false){
    e_posG = 0;
    e_pos_preG = 0;
    e_pos_sumG = 0;
    pwm_pulseG = 0;
    } 
 
  pwmOutG(pwm_pulseG);
  
  }
void calcPID_D(double e_posD){

  if(e_posD<5&&  e_posD>=0){
    e_posD = 0;
    e_pos_preD = 0;
    e_pos_sumD = 0;
    pwm_pulseD = 0;
   }
   else if(e_posD>-5 &&  e_posD<=0){
    e_posD = 0;
    e_pos_preD = 0;
    e_pos_sumD = 0;
    pwm_pulseD = 0;
   }
    pwm_pulseD = e_posD*kp + ki*e_pos_sumD + ((e_posD - e_pos_preD)/interval)*kd;
     e_pos_sumD += e_posD*interval; //sum of error
     if(e_pos_sumD>255.00)e_pos_sumD=255.00;
     if(e_pos_sumD<-255.00)e_pos_sumD=-255.00;
    e_pos_preD = encoderPosD;  //save last (previous) error
   
   if(motor_start==false){
     e_posD = 0;
    e_pos_preD = 0;
    e_pos_sumD = 0;
    pwm_pulseD = 0;
    } 
 
  pwmOutD(pwm_pulseD);
  
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

void pwmOutG(double out) {  
 
  if (out > 0.00) {
    if(out>255.00){
      analogWrite(pin_fwdG,255.00);                                // Rotate the motor CW
      analogWrite(pin_bwdG, 0);
      }
     else{
    analogWrite(pin_fwdG,out);                                // Rotate the motor CW
    analogWrite(pin_bwdG, 0);
     }
  }
  else {
    if(out<-255.00){
      analogWrite(pin_fwdG, 0);
      analogWrite(pin_bwdG, 255.00); 
    }
    else{
    analogWrite(pin_fwdG, 0);
    analogWrite(pin_bwdG, abs(out)); 
    }// Rotate the motor CCW
  }
}
void pwmOutD(double out) { // to H-Bridge board

  if (out > 0.00) {
    if(out>255.00){
      analogWrite(pin_fwdD,255.00);                                // Rotate the motor CW
      analogWrite(pin_bwdD, 0);
      }
     else{
    analogWrite(pin_fwdD,out);                                // Rotate the motor CW
    analogWrite(pin_bwdD, 0);
     }
  }
  else {
    if(out<-255.00){
      analogWrite(pin_fwdD, 0);
      analogWrite(pin_bwdD, 255.00); 
    }
    else{
    analogWrite(pin_fwdD, 0);
    analogWrite(pin_bwdD, abs(out)); 
    }// Rotate the motor CCW
  }
}
void encoderG()  {                                     // pulse and direction, direct port reading to save cycles
 if(PIND & B10000000)   encoderPosG ++;
 else  encoderPosG --;
}
void encoderD()  {                                     // pulse and direction, direct port reading to save cycles
 if(PINB & B00000001)   encoderPosD --;
 else  encoderPosD ++;
}

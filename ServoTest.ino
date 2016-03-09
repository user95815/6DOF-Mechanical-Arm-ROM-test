//ARM servo calibratiom************************************************************
//  by User95815
// written for range testing of a 6DOF Robotic Arm and Adafruit 16 ch. servo shield
//*********************************************************************************
// always include the libraries 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); // addresses the board default 0x40

const int LED = 13; // Warning LED connected to digital pin 13

int delayPeriod0 = 5; //servonum0 speed  //these will need changing for the different sub routines 
int delayPeriod1 = 5; //servonum1 speed // the lower these delay are the faster the servos move
int delayPeriod2 = 5; //servonum2 speed
int delayPeriod3 = 5; //servonum3 speed
int delayPeriod4 = 10; //servonum4 speed
int delayPeriod5 = 10; //servonum5 speed
int delayPeriod6 = 500; //for servo speed to position --range speed

#define SERVOMIN0  445 // servonum0 claw open (lower to open) out of 4096 (445 min)
#define SERVOMAX0  590 // servomun0 claw closed  (raise to close) (590 max)
#define SERVOMIN1  150 // servonum1 wrist counter clockwise (lower to counter clockwise)  (150 min)
#define SERVOMAX1  580 // servonum1 wrist clockwise (lower to counter clockwise) (580 max)
#define SERVOMIN2  150 // servonum2 wrist down (to go down lower) (150 min)
#define SERVOMAX2  450 // servonum2 wrist up (raise to go up) (450 max)
#define SERVOMIN3  160 // servonum3 elbow (160 min)
#define SERVOMAX3  250 // servonum3 elbow (250 max)
#define SERVOMIN4  130 // servonum4 shoulder (130 min)
#define SERVOMAX4  480 // servonum4 shoulder (480 max
#define SERVOMIN5  150 // servonum5 base rotation (150 min)
#define SERVOMAX5  510 // servonum5 base rotation (510 max)

uint8_t servonum0 = 0; //claw servo
uint8_t servonum1 = 1; //wrist servo
uint8_t servonum2 = 2; //wrist servo
uint8_t servonum3 = 3; //elbow servo
uint8_t servonum4 = 4; //shoulder servo
uint8_t servonum5 = 5; //base servo

//**************************************MAIN SET UP***********************************
void setup() {
  
  pinMode(LED, OUTPUT); // sets the digital pin as output
digitalWrite(LED, HIGH); //Turn led red warning LED on

 pwm.begin(); // begin PWM
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  
}

//**************************************END SET UP************************************

//**************************************MAIN LOOP*************************************

// **warning** all1 servos running from MIN to MAX positions 

void loop()
{
  //singleservo(); single servo movement testing for calabration 

  all2(); // as seen in the video
  //rest(); // sitting up nice and quiet



  
}
    
//**************************************END LOOP**************************************

//**************************************REST*******************************************

void rest() {
  pwm.setPWM(servonum0, 0, 590);
  delay(2);
  pwm.setPWM(servonum1, 0, 500);
  delay(2);
  pwm.setPWM(servonum2, 0, 150);
  delay(2);
  pwm.setPWM(servonum3, 0, 160);
  delay(2);
  pwm.setPWM(servonum4, 0, 130);
  delay(2);
  pwm.setPWM(servonum5, 0, 330);
  delay(2);
}
//**************************************END REST****************************************



//***************************singleservo singleservo**********************************

void singleservo() {
  
  for (uint16_t pulselen = SERVOMIN1; pulselen < SERVOMAX1; pulselen++) {
    pwm.setPWM(servonum1, 0, pulselen);
    delay(5);
  }
  delay(500);
    for (uint16_t pulselen = SERVOMAX1; pulselen > SERVOMIN1; pulselen--) {
    pwm.setPWM(servonum1, 0, pulselen);
    delay(5);
  }
}
//********************************END singleservo++++++++++++++++++++++++++++++++++++++  





//***************************all2 all2 all2 all2 all2 ********************************

void all2() {
  
  for (uint16_t pulselen = SERVOMIN0; pulselen < SERVOMAX0; pulselen++) {
    pwm.setPWM(servonum0, 0, pulselen);
    //delay(delayPeriod0);
  }
    for (uint16_t pulselen = SERVOMAX0; pulselen > SERVOMIN0; pulselen--) {
    pwm.setPWM(servonum0, 0, pulselen);
    delay(delayPeriod0);
  }
  delay(200);
   for (uint16_t pulselen = SERVOMIN1; pulselen < SERVOMAX1; pulselen++) {
    pwm.setPWM(servonum1, 0, pulselen);
    //delay(delayPeriod1);
  }
    for (uint16_t pulselen = SERVOMAX1; pulselen > SERVOMIN1; pulselen--) {
    pwm.setPWM(servonum1, 0, pulselen);
    delay(delayPeriod1);
  }
  for (uint16_t pulselen = SERVOMIN2; pulselen < SERVOMAX2; pulselen++) {
    pwm.setPWM(servonum2, 0, pulselen);
    delay(delayPeriod2);
  }
    for (uint16_t pulselen = SERVOMAX2; pulselen > SERVOMIN2; pulselen--) {
    pwm.setPWM(servonum2, 0, pulselen);
    delay(delayPeriod2);
  }
  for (uint16_t pulselen = SERVOMIN3; pulselen < SERVOMAX3; pulselen++) {
    pwm.setPWM(servonum3, 0, pulselen);
    delay(delayPeriod3);
  }
    for (uint16_t pulselen = SERVOMAX3; pulselen > SERVOMIN3; pulselen--) {
    pwm.setPWM(servonum3, 0, pulselen);
    delay(delayPeriod3);
  }
  for (uint16_t pulselen = SERVOMIN5; pulselen < SERVOMAX5; pulselen++) {
    pwm.setPWM(servonum5, 0, pulselen);
    delay(delayPeriod5);
   }
     for (uint16_t pulselen = SERVOMAX5; pulselen > SERVOMIN5; pulselen--) {
    pwm.setPWM(servonum5, 0, pulselen);
    delay(delayPeriod5);
  }
  
 delay(delayPeriod6);

} 
//*******************************END ALL2*********************************************

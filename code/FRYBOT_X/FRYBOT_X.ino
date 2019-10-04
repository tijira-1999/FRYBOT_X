#include <Servo.h>

Servo cam_top;
Servo cam_base;
Servo arm_grip;
Servo arm_wrist;
Servo arm_elbow;
Servo arm_base;

int channel[6];

const int buzzer = 13;
const int ultrasonic = 2;

//Define variable for the motors speeds
int RightSpd = 130;
int LeftSpd = 130;

//Define enable pins of the Motors
const int enbA = 3;
const int enbB = 11;

//Define control pins of the Motors
const int IN1 = A3;    //Left Motor (-)
const int IN2 = A2;    //Left Motor (+)
const int IN3 = A1;    //Right Motor (+)
const int IN4 = A0;    //Right Motor (-)

void setup() 
{
    // put your setup code here, to run once:

   // receiver pins
    pinMode(10,INPUT);  //channel 1
    pinMode(5,INPUT);   //channel 2
    pinMode(6,INPUT);   //channel 3
    pinMode(9,INPUT);   //channel 4 
    pinMode(1,INPUT);   //channel 5
    pinMode(0,INPUT);   //channel 6

   // auxilliary functions
    pinMode(buzzer, OUTPUT);
    pinMode(ultrasonic, OUTPUT);
    digitalWrite(buzzer, LOW);  //buzzer
    digitalWrite(ultrasonic, LOW);   //ultrasonic sensor

   // servo pins
    cam_top.attach(4);
    cam_base.attach(12);
    arm_grip.attach(7);
    arm_wrist.attach(8);
    arm_elbow.attach(A5);
    arm_base.attach(A4);

   // Define the motor pins as OUTPUT
    pinMode(enbA, OUTPUT);
    pinMode(enbB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  channel[0] = pulseIn(10,HIGH);
  channel[1] = pulseIn(5,HIGH);
  channel[2] = pulseIn(6,HIGH);
  channel[3] = pulseIn(9,HIGH);
  channel[4] = pulseIn(1,HIGH);
  channel[5] = pulseIn(0,HIGH);

  if(channel[5]<1100){
    
    //normal mode
    
//    int norm_for = map(channel[1],1650,1994,0,255);
//    int norm_back = map(channel[1],1350,994,0,255);
//    int norm_right = map(channel[0],1350,994,0,255);
//    int norm_left = map(channel[0],1650,1994,0,255);

    if(channel[1]>=1650 && channel[1]<=1994 && channel[0]>1350 && channel[0]<1650)
      {
            
         int norm_for = map(channel[1],1650,1994,0,255);
            
         // forward
         analogWrite(enbA, norm_for);
         analogWrite(enbB, norm_for);
         digitalWrite(IN1, LOW);
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
      }
    
    else if(channel[1]>=993 && channel[1]<=1350 && channel[0]>1350 && channel[0]<1650)
      {

         int norm_back = map(channel[1],1350,993,0,255);
         
         // backward
         analogWrite(enbA, norm_back);
         analogWrite(enbB, norm_back);
         digitalWrite(IN1, HIGH);
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
      }

    else if(channel[0]>=993 && channel[0]<=1350 && channel[1]>1350 && channel[1]<1650)
      {

         int norm_right = map(channel[0],1350,993,0,255);
         
         // right
         analogWrite(enbA, norm_right);
         analogWrite(enbB, norm_right);
         digitalWrite(IN1, LOW);
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
      }
      
    else if(channel[0]>=1650 && channel[0]<=1994 && channel[1]>1350 && channel[1]<1650)
      {

         int norm_left = map(channel[0],1650,1994,0,255);
         
         // left
         analogWrite(enbA, norm_left);
         analogWrite(enbB, norm_left);
         digitalWrite(IN1, HIGH);
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
      }

    else
      {
          // stop
          analogWrite(enbA, 0);
          analogWrite(enbB, 0);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
      }
      
  }
  
  else if(channel[5]>1400 && channel[5]<1500){
    //ultrasonic sensor mode
  }
  else if(channel[5]>1850){
    //gripping mode
  }
  else {
    //error
  }

//      // back
//      analogWrite(enbA, LeftSpd);
//      analogWrite(enbB, RightSpd);
//      digitalWrite(IN1, HIGH);
//      digitalWrite(IN2, LOW);
//      digitalWrite(IN3, LOW);
//      digitalWrite(IN4, HIGH);
  
}

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
    
//   Serial.begin(9600);
    
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
  
//  Serial.print("channel[0]  ");
//  Serial.println(channel[0]);
//  Serial.println(" ");
//  delay(100);
//  Serial.print("channel[1]  ");
//  Serial.println(channel[1]);
//  Serial.println(" ");
//  
//  Serial.print("channel[2]  ");
//  Serial.println(channel[2]);
//  Serial.println(" ");
// 
//  Serial.print("channel[3]  ");
//  Serial.println(channel[3]);
//  Serial.println(" ");
//
//  Serial.print("channel[4]  ");
//  Serial.println(channel[4]);
//  Serial.println(" ");
//  delay(1000);

  if(channel[5]<1100){
    //normal mode
    int norm_for = map(channel[1],1450,1990,0,255);
    int norm_back = map(channel[1],1450,1990,0,255);
    int norm_right = map(channel[0],1450,1990,0,255);
    int norm_left = map(channel[0],1450,1990,0,255);
    
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

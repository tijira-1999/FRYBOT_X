#include <Servo.h>

Servo cam_top;
Servo cam_base;
Servo arm_grip;
Servo arm_wrist;
Servo arm_elbow;
Servo arm_base;

double channel[6];

const int buzzer = 13;
const int ultrasonic = 2;

//Define enable pins of the Motors
const int enbA = 10;
const int enbB = 11;

//Define control pins of the Motors
//If the motors rotate in the opposite direction, you can change the positions of the following pin numbers
const int IN1 = A3;    //Right Motor (-)
const int IN2 = A2;    //Right Motor (+)
const int IN3 = A1;    //Left Motor (+)
const int IN4 = A0;    //Right Motor (-)

void setup() 
{
    // put your setup code here, to run once:

   // receiver pins
    pinMode(3,INPUT);  //channel 1
    pinMode(5,INPUT);  //channel 2
    pinMode(6,INPUT);  //channel 3
    pinMode(9,INPUT);  //channel 4 
    pinMode(1,INPUT);  //channel 5
    pinMode(0,INPUT);  //channel 6

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
    
   //Serial.begin(9600);
    
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  channel[0] = pulseIn(3,HIGH);
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

  if(channel[5]>970 && channel[5]<1100){
    //normal mode
  }
  
  else if(channel[5]>1400 && channel[5]<1500){
    //ultrasonic sensor mode
  }
  else if(channel[5]>1900 && channel[5]<2000){
    //gripping mode
  }
  else {
    //error
  }
  
}

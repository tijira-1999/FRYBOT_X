#include <Servo.h>
#include <pitches.h> //add note library

//notes in the melody
int melody[]={NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

//note durations. 4=quarter note / 8=eighth note
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};

Servo cam_top;
Servo cam_base;
Servo arm_grip;
Servo arm_wrist;
Servo arm_elbow;
Servo arm_base;

int channel[6];

const int buzzer = 13;
const int ultrasonic = 2;


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
   
   //startup initiates wait for 2 seconds henceforth
    for (int thisNote=0; thisNote <8; thisNote++)
     {
      //to calculate the note duration, take one second. Divided by the note type
      int noteDuration = 1000 / noteDurations [thisNote];
      tone(buzzer, melody [thisNote], noteDuration);

      //to distinguish the notes, set a minimum time between them
      //the note's duration +30% seems to work well
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      //stop the tone playing
      noTone(buzzer);
     }
   
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

   // servo initial position
    cam_top.write(110);
    cam_base.write(100);
    arm_grip.write(90);
    arm_wrist.write(84);
    arm_elbow.write(179);
    arm_base.write(3);
    delay(1000);

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

   //startup complete
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(100);
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

  if(channel[5]<1100)
  { 
   //normal mode

    digitalWrite(ultrasonic, LOW);   //ultrasonic sensor off
    arm_wrist.write(84);
    arm_elbow.write(179);
    arm_base.write(3);

   //camera 
    int norm_cam_top = map(channel[2],994,1986,48,150);
    int norm_cam_base = map(channel[3],1986,994,0,163);
    
    cam_top.write(norm_cam_top);
    cam_base.write(norm_cam_base);


   // gripper
    int norm_grip = map(channel[4],993,1986,180,0);
    arm_grip.write(norm_grip);


   //buzzer
    if(channel[4]<=1010)
    {
      digitalWrite(buzzer, HIGH);  //buzzer on
    }
    else
    {
      digitalWrite(buzzer, LOW);  //buzzer off
    }

    
   // car
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
  
  else if(channel[5]>1400 && channel[5]<1500)
  {
   //ultrasonic sensor mode

    digitalWrite(ultrasonic, HIGH);   //ultrasonic sensor ON
    arm_wrist.write(84);
    arm_elbow.write(179);
    arm_base.write(3);

   //camera 
    int ultra_cam_top = map(channel[2],994,1986,48,150);
    int ultra_cam_base = map(channel[3],1986,994,0,163);
    
    cam_top.write(ultra_cam_top);
    cam_base.write(ultra_cam_base);


   // gripper
    int ultra_grip = map(channel[4],993,1986,180,0);
    arm_grip.write(ultra_grip);


   //buzzer
    if(channel[4]<=1010)
    {
      digitalWrite(buzzer, HIGH);  //buzzer on
    }
    else
    {
      digitalWrite(buzzer, LOW);  //buzzer off
    }

    if(channel[1]>=1650 && channel[1]<=1994 && channel[0]>1350 && channel[0]<1650)
      {
            
         int ultra_for = map(channel[1],1650,1994,0,255);
            
        // forward
         analogWrite(enbA, ultra_for);
         analogWrite(enbB, ultra_for);
         digitalWrite(IN1, LOW);
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
      }
    
    else if(channel[1]>=993 && channel[1]<=1350 && channel[0]>1350 && channel[0]<1650)
      {

         int ultra_back = map(channel[1],1350,993,0,255);
         
        // backward
         analogWrite(enbA, ultra_back);
         analogWrite(enbB, ultra_back);
         digitalWrite(IN1, HIGH);
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
      }

    else if(channel[0]>=993 && channel[0]<=1350 && channel[1]>1350 && channel[1]<1650)
      {

         int ultra_right = map(channel[0],1350,993,0,255);
         
        // right
         analogWrite(enbA, ultra_right);
         analogWrite(enbB, ultra_right);
         digitalWrite(IN1, LOW);
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
      }
      
    else if(channel[0]>=1650 && channel[0]<=1994 && channel[1]>1350 && channel[1]<1650)
      {

         int ultra_left = map(channel[0],1650,1994,0,255);
         
        // left
         analogWrite(enbA, ultra_left);
         analogWrite(enbB, ultra_left);
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

  
  else if(channel[5]>1850)
  {
    //gripping mode

    digitalWrite(ultrasonic, LOW);   //ultrasonic sensor off
    cam_top.write(110);              // position camera top servo to center
    
   //camera 
    // only camera base can be moved in this mode
    int grip_cam_base = map(channel[3],1986,994,0,163);
    
    cam_base.write(grip_cam_base);

   // gripper
    int grip_grip = map(channel[4],993,1986,180,0);
    arm_grip.write(grip_grip);


   //buzzer
    if(channel[4]<=1010)
    {
      digitalWrite(buzzer, HIGH);  //buzzer on
    }
    else
    {
      digitalWrite(buzzer, LOW);  //buzzer off
    }

    // arm movement
    
     int grip_wrist = map(channel[0],1994,993,0,180);
     int grip_elbow = map(channel[2],993,1987,177,0);    //177 instead of 179 to reduce jitters
     int grip_base = map(channel[1],1500,1994,5,118);    //5 instead of 3 to reduce jitters

     arm_wrist.write(grip_wrist);
     arm_elbow.write(grip_elbow);
     arm_base.write(grip_base);
    
    // stop the car
     analogWrite(enbA, 0);
     analogWrite(enbB, 0);
     digitalWrite(IN1, LOW);
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
  }

  
  else 
  {
    //error
  }

  
}

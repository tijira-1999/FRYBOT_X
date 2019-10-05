#include <Servo.h>

Servo cam_top;
Servo cam_base;
Servo arm_grip;
Servo arm_wrist;
Servo arm_elbow;
Servo arm_base;

void setup() {
  // put your setup code here, to run once:
  // servo pins
    cam_top.attach(4);
    cam_base.attach(12);
    arm_grip.attach(7);
    arm_wrist.attach(8);
    arm_elbow.attach(A5);
    arm_base.attach(A4);


}

void loop() {
  // put your main code here, to run repeatedly:
  // servo pins
    cam_top.write(110);
    cam_base.write(100);
    arm_grip.write(90);
    arm_wrist.write(84);
    arm_elbow.write(179);
    arm_base.write(3);
    delay(1000);


}


#include<Servo.h>
//we have to set them up as global variables;
  Servo Myservo1;
  Servo Myservo2;
  Servo Myservo3;
  Servo Myservo4;
  Servo Myservo5;
  Servo Myservo6;
  Servo Myservo7;
  Servo Myservo8;
  Servo Myservo9;
  Servo Myservo10;


void setup() {
    Myservo1.attach(3);
  Myservo2.attach(4);
  Myservo3.attach(5);
  Myservo4.attach(6);
  Myservo5.attach(7);
  Myservo6.attach(8);
  Myservo7.attach(9);
  Myservo8.attach(10);
  Myservo9.attach(11);
  Myservo10.attach(12);
  Serial.begin(9600);
  Serial.println('\u002f');

}

void loop() {
  // put your main code here, to run repeatedly:

}

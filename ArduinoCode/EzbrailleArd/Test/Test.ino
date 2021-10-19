
#include<Servo.h>
//we have to set them up as global variables;
  Servo Myservo1;
  Servo motorlist[] = {Myservo1};
  char lister[] = {'d','b','a','c','a'};
void setup() {
  Myservo1.attach(3);
  Serial.begin(9600);
  Serial.println("intialize");

  for (int i = 0; i < 5; i++){
    Compare(lister[i],motorlist[0]);
    delay(1000);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  
}


int Compare(char x, Servo motorleft){
  switch (x) {
    case 'a':
      motorleft.write(40);
      Serial.println(x);
      break;
    case 'b':
      motorleft.write(90);
      Serial.println(x);
      break;
    case 'c':
      motorleft.write(0);
      Serial.println(x);
      break;
    case 'd':
      motorleft.write(150);
      Serial.println(x);
      break;
    default:
      break;
  }
}

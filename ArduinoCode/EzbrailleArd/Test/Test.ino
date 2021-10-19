
#include<Servo.h>
//we have to set them up as global variables;
  Servo Myservo1;
  Servo motorlist[] = {Myservo1};
  char lister[] = {'d','b','d'};
void setup() {
  Myservo1.attach(3);
  Serial.begin(9600);
  Serial.println("intialize");

  for (int i = 0; i < 3; i++){
    Compare(lister[i],motorlist[0]);
    delay(1000);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  
}


int Compare(char x, Servo motorleft){
  switch (x) {
    case 'b':
      motorleft.write(40);
      Serial.println(x);
      break;
    case 'd':
      motorleft.write(90);
      Serial.println(x);
      break;
    default:
      break;
  }
}

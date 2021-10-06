
#include<Servo.h>

void setup() {
  // put your setup code here, to run once:
  Servo Myservo;
  Myservo.attach(3);
  Serial.print(78);

}

void loop() {
  // put your main code here, to run repeatedly:

}

//just define the switch case here don't bother about the rest
//note each case must be with with single quotation mark. i.e. 'k' not "k", double quotation will be treated as a string.
int Compare(char x){
  int result;
  switch (x) {
    case ' ':
      // this is space mapped to the empty cell
      break;
    case '!':
      //'!' -> '⠁'
      // this is the translation '!' -> '⠁'
      break;
    case '"':
      //'"' -> ''
      break;
    case '#':
      //'#' -> ''
      break;
    default:
      // default case is if everything above fails
      break;
  }
  return result;
 }


#include<Servo.h>

void setup() {
  // put your setup code here, to run once:
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

 //Servo[10] servoarray = {servo1,servo2};
}

void loop() {
  // put your main code here, to run repeatedly:

}

//just define the switch case here don't bother about the rest
//note each case must be with with single quotation mark. i.e. 'k' not "k", double quotation will be treated as a string.


//for (int i = 0; i < 5; i++){
//    filesyst.read5();
//    Compare(filesyst.current[i],servoarray[i],servoarray[i+5]);
//}



int Compare(char x, Servo motorleft, Servo motorright){
  int result;
  switch (x) {
    case ' ':
      // this is space mapped to the empty cell
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case '!':
      //'!' -> '⠮'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case '"':
      //'"' -> '⠐'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case '#':
      //'#' -> '⠼' 
      motorleft.write(angleleft)
      motorright.write(angleright
      break
    case'$': 
      //'$' -> '⠫'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'%':
      //'%' -> '⠩'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'&':
      //'&' ->'⠯'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case''':
      //''' ->'⠄'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'(':
      //'(' ->'⠷'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case')':
      //')' ->'⠾'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'*':
      //'*' ->'⠡'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'+':
      //'+' ->'⠬'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case',':
      //',' ->'⠠'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'-':
      //'-' ->'⠤'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'.':
      //'.' ->'⠨'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'/':
      //'/' ->'⠌'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'0':
      //'0' ->'⠴'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'1':
      //'1' ->'⠂'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'2':
      //'2' ->'⠆'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'3':
      //'3' ->'⠒'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'4':
      //'4' ->'⠲'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'5':
      //'5' ->'⠢'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'6':
      //'6' ->'⠖'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'7':
      //'7' ->'⠶'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'8':
      //'8' ->'⠦'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'9':
      //'9' ->'⠔'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case':':
      //':' ->'⠱'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case';':
      //';' ->'⠰'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'<':
      //'<' ->'⠣'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'=':
      //'=' ->'⠿'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'>':
      //'>' ->'⠜'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'?':
      //'?' ->'⠹'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'@':
      //'@' ->'⠈'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'A':
      //'A' ->'⠁'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'B':
      //'B' ->'⠃'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'C':
      //'C' ->'⠉'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'D':
      //'D' ->'⠙'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'E':
      //'E' ->'⠑'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'F':
      //'F' ->'⠋'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'G':
      //'G' ->'⠛'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'H':
      //'H' ->'⠓'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'I':
      //'I' ->'⠊'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'J':
      //'J' ->'⠚'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'K':
      //'K' ->'⠅'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'L':
      //'L' ->'⠇'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'M':
      //'M' ->'⠍'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'N':
      //'N' ->'⠝'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'O':
      //'O' ->'⠕'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'P':
      //'P' ->'⠏'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'Q':
      //'Q' ->'⠟'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'R':
      //'R' ->'⠗'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'S':
      //'S' ->'⠎'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'T':
      //'T' ->'⠞'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'U':
      //'U' ->'⠥'
      motorleft.write(angleleft)
      motorright.write(angleright
      break;
    case'V':
      //'V' ->'⠧'
      motorleft.write(angleleft)
      motorright.write(angleright)
      break;
    case'W':
      //'W' ->'⠺'
      motorleft.write(angleleft)
      motorright.write(angleright)
      break;
    case'X':
      //'X' ->'⠭'
      motorleft.write(angleleft)
      motorright.write(angleright)
      break;
    case'Y':
      //'Y' ->'⠽'
      motorleft.write(angleleft)
      motorright.write(angleright)
      break;
    case'Z':
      //'Z' ->'⠵'
      motorleft.write(angleleft)
      motorright.write(angleright)
      break;
    case']':
      //']' ->'⠻'
      motorleft.write(angleleft)
      motorright.write(angleright)
      break;
    case'[':
      //'[' ->'⠪'
      motorleft.write(angleleft)
      motorright.write(angleright)
      break;
    case'/':
      //'/' ->'⠌'
      motorleft.write(angleleft)
      motorright.write(angleright))
      break;
    case'^':
      //'^' ->'⠘'
      motorleft.write(angleleft)
      motorright.write(angleright)
      break;
    case'_':
      //'_' ->'⠸⠸'
      motorleft.write(angleleft)
      motorright.write(angleright)
      break;
    default:
      // default case is if everything above fails
      break;
  }
  return result;
 }

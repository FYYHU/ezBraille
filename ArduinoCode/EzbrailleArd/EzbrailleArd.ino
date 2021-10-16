
#include<Servo.h>

void setup() {
  // put your setup code here, to run once:
  Servo Myservo1;
  Servo Myservo2;
  Myservo1.attach(3);
  Myservo2.attach(4);

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
      //ie motorleft.write(angleleft)
      //motorright.wright(angleright)
      break;
    case '!':
      //'!' -> '⠮'
      break;
    case '"':
      //'"' -> '⠐'
      break;
    case '#':
      //'#' -> '⠼' 
      break
    case'$': 
      //'$' -> '⠫'
      break;
    case'%':
      //'%' -> '⠩'
      break;
    case'&':
      //'&' ->'⠯'
      break;
    case''':
      //''' ->'⠄'
      break;
    case'(':
      //'(' ->'⠷'
      break;
    case')':
      //')' ->'⠾'
      break;
    case'*':
      //'*' ->'⠡'
      break;
    case'+':
      //'+' ->'⠬'
      break;
    case',':
      //',' ->'⠠'
      break;
    case'-':
      //'-' ->'⠤'
      break;
    case'.':
      //'.' ->'⠨'
      break;
    case'/':
      //'/' ->'⠌'
      break;
    case'0':
      //'0' ->'⠴'
      break;
    case'1':
      //'1' ->'⠂'
      break;
    case'2':
      //'2' ->'⠆'
      break;
    case'3':
      //'3' ->'⠒'
      break;
    case'4':
      //'4' ->'⠲'
      break;
    case'5':
      //'5' ->'⠢'
      break;
    case'6':
      //'6' ->'⠖'
      break;
    case'7':
      //'7' ->'⠶'
      break;
    case'8':
      //'8' ->'⠦'
      break;
    case'9':
      //'9' ->'⠔'
      break;
    case':':
      //':' ->'⠱'
      break;
    case';':
      //';' ->'⠰'
      break;
    case'<':
      //'<' ->'⠣'
      break;
    case'=':
      //'=' ->'⠿'
      break;
    case'>':
      //'>' ->'⠜'
      break;
    case'?':
      //'?' ->'⠹'
      break;
    case'@':
      //'@' ->'⠈'
      break;
    case'A':
      //'A' ->'⠁'
      break;
    case'B':
      //'B' ->'⠃'
      break;
    case'C':
      //'C' ->'⠉'
      break;
    case'D':
      //'D' ->'⠙'
      break;
    case'E':
      //'E' ->'⠑'
      break;
    case'F':
      //'F' ->'⠋'
      break;
    case'G':
      //'G' ->'⠛'
      break;
    case'H':
      //'H' ->'⠓'
      break;
    case'I':
      //'I' ->'⠊'
      break;
    case'J':
      //'J' ->'⠚'
      break;
    case'K':
      //'K' ->'⠅'
      break;
    case'L':
      //'L' ->'⠇'
      break;
    case'M':
      //'M' ->'⠍'
      break;
    case'N':
      //'N' ->'⠝'
      break;
    case'O':
      //'O' ->'⠕'
      break;
    case'P':
      //'P' ->'⠏'
      break;
    case'Q':
      //'Q' ->'⠟'
      break;
    case'R':
      //'R' ->'⠗'
      break;
    case'S':
      //'S' ->'⠎'
      break;
    case'T':
      //'T' ->'⠞'
      break;
    case'U':
      //'U' ->'⠥'
      break;
    case'V':
      //'V' ->'⠧'
      break;
    case'W':
      //'W' ->'⠺'
      break;
    case'X':
      //'X' ->'⠭'
      break;
    case'Y':
      //'Y' ->'⠽'
      break;
    case'Z':
      //'Z' ->'⠵'
      break;
    case']':
      //']' ->'⠻'
      break;
    case'[':
      //'[' ->'⠪'
      break;
    case'/':
      //'/' ->'⠌'
      break;
    case'^':
      //'^' ->'⠘'
      break;
    case'_':
      //'_' ->'⠸⠸'
      break;
    default:
      // default case is if everything above fails
      break;
  }
  return result;
 }


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
  
  Servo[] servoarray = {Myservo1, Myservo2, Myservo3,Myservo4,Myservo5,Myservo6,Myservo7,Myservo8,Myservo9,Myservo10};

void setup() {
  // put your setup code here, to run once:
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



//motor char comparison
int Compare(char x, Servo motorleft, Servo motorright){
  int result;
  int angleleft = 5;//tempo filled just to make verify work
  int angleright = 4;
  switch (x) {
	    case ' ':
	      // this is space mapped to the empty cell
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '!':
	      //'!' -> '⠮'
	      motorleft.write(108);
	      motorright.write(18);
	      break;
	    case '"':
	      //'"' -> '⠐'
	      motorleft.write(108);
	      motorright.write(36);
	      break;
	    case '#':
	      //'#' -> '⠼' 
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '$': 
	      //'$' -> '⠫'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '%':
	      //'%' -> '⠩'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '&':
	      //'&' ->'⠯'
	      motorleft.write(72);
	      motorright.write(120);
	      break;
	    case'\u0027':
	      //''' ->'⠄'
	      motorleft.write(108);
	      motorright.write(36);
	      break;
	    case '(':
	      //'(' ->'⠷'
	      motorleft.write(72);
	      motorright.write(108);
	      break;
	    case ')':
	      //')' ->'⠾'
	      motorleft.write(108);
	      motorright.write(72);
	      break;
	    case '*':
	      //'*' ->'⠡'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '+':
	      //'+' ->'⠬'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case ',':
	      //',' ->'⠠'
	      motorleft.write(18);
	      motorright.write(54);
	      break;
	    case '-':
	      //'-' ->'⠤'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '.':
	      //'.' ->'⠨'
	      motorleft.write(18);
	      motorright.write(108);
	      break;
	    case '/':
	      //'/' ->'⠌'
	      motorleft.write(36);
	      motorright.write(0);
	      break;
	    case '0':
	      //'0' ->'⠴'
	      motorleft.write(18);
	      motorright.write(90);
	      break;
	    case '1':
	      //'1' ->'⠂'
	      motorleft.write(0);
	      motorright.write(54);
	      break;
	    case '2':
	      //'2' ->'⠆'
	      motorleft.write(90);
	      motorright.write(54);
	      break;
	    case '3':
	      //'3' ->'⠒'
	      motorleft.write(0);
	      motorright.write(0);
	      break;
	    case '4':
	      //'4' ->'⠲'
	      motorleft.write(0);
	      motorright.write(90);
	      break;
	    case '5':
	      //'5' ->'⠢'
	      motorleft.write(0);
	      motorright.write(18);
	      break;
	    case '6':
	      //'6' ->'⠖'
	      motorleft.write(90);
	      motorright.write(0);
	      break;
	    case '7':
	      //'7' ->'⠶'
	      motorleft.write(90);
	      motorright.write(90);
	      break;
	    case '8':
	      //'8' ->'⠦'
	      motorleft.write(90);
	      motorright.write(18);
	      break;
	    case '9':
	      //'9' ->'⠔'
	      motorleft.write(18);
	      motorright.write(0);
	      break;
	    case ':':
	      //':' ->'⠱'
	      motorleft.write(18);
	      motorright.write(18);
	      break;
	    case ';':
	      //';' ->'⠰'
	      motorleft.write(108);
	      motorright.write(54);
	      break;
	    case '<':
	      //'<' ->'⠣'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '=':
	      //'=' ->'⠿'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '>':
	      //'>' ->'⠜'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '?':
	      //'?' ->'⠹'
	      motorleft.write(108);
	      motorright.write(36);
	      break;
	    case '@':
	      //'@' ->'⠈'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case 'A':
	      //'A' ->'⠁'
	      motorleft.write(0);
	      motorright.write(54);
	      break;
	    case 'B':
	      //'B' ->'⠃'
	      motorleft.write(90);
	      motorright.write(54);
	      break;
	    case 'C':
	      //'C' ->'⠉'
	      motorleft.write(0);
	      motorright.write(0);
	      break;
	    case 'D':
	      //'D' ->'⠙'
	      motorleft.write(0);
	      motorright.write(90);
	      break;
	    case 'E':
	      //'E' ->'⠑'
	      motorleft.write(0);
	      motorright.write(18);
	      break;
	    case 'F':
	      //'F' ->'⠋'
	      motorleft.write(90);
	      motorright.write(0);
	      break;
	    case 'G':
	      //'G' ->'⠛'
	      motorleft.write(90);
	      motorright.write(90);
	      break;
	    case 'H':
	      //'H' ->'⠓'
	      motorleft.write(90);
	      motorright.write(18);
	      break;
	    case 'I':
	      //'I' ->'⠊'
	      motorleft.write(18);
	      motorright.write(0);
	      break;
	    case 'J':
	      //'J' ->'⠚'
	      motorleft.write(18);
	      motorright.write(90);
	      break;
	    case 'K':
	      //'K' ->'⠅'
	      motorleft.write(120);
	      motorright.write(54);
	      break;
	    case 'L':
	      //'L' ->'⠇'
	      motorleft.write(72);
	      motorright.write(54);
	      break;
	    case 'M':
	      //'M' ->'⠍'
	      motorleft.write(120);
	      motorright.write(0);
	      break;
	    case 'N':
	      //'N' ->'⠝'
	      motorleft.write(120);
	      motorright.write(90);
	      break;
	    case 'O':
	      //'O' ->'⠕'
	      motorleft.write(120);
	      motorright.write(18);
	      break;
	    case 'P':
	      //'P' ->'⠏'
	      motorleft.write(72);
	      motorright.write(0);
	      break;
	    case 'Q':
	      //'Q' ->'⠟'
	      motorleft.write(72);
	      motorright.write(90);
	      break;
	    case 'R':
	      //'R' ->'⠗'
	      motorleft.write(72);
	      motorright.write(18);
	      break;
	    case 'S':
	      //'S' ->'⠎'
	      motorleft.write(108);
	      motorright.write(0);
	      break;
	    case 'T':
	      //'T' ->'⠞'
	      motorleft.write(108);
	      motorright.write(90);
	      break;
	    case 'U':
	      //'U' ->'⠥'
	      motorleft.write(120);
	      motorright.write(54);
	      break;
	    case 'V':
	      //'V' ->'⠧'
	      motorleft.write(72);
	      motorright.write(54);
	      break;
	    case 'W':
	      //'W' ->'⠺'
	      motorleft.write(18);
	      motorright.write(72);
	      break;
	    case 'X':
	      //'X' ->'⠭'
	      motorleft.write(120);
	      motorright.write(120);
	      break;
	    case 'Y':
	      //'Y' ->'⠽'
	      motorleft.write(120);
	      motorright.write(72);
	      break;
	    case 'Z':
	      //'Z' ->'⠵'
	      motorleft.write(120);
	      motorright.write(108);
	      break;
	    case ']':
	      //']' ->'⠻'
	      motorleft.write(108);
	      motorright.write(108);
	      break;
	    case '[':
	      //'[' ->'⠪'
	      motorleft.write(108);
	      motorright.write(108);
	      break;
	    case '\u005c':
	      //'\' ->'⠌'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '^':
	      //'^' ->'⠘'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '_':
	      //'_' ->'⠸⠸'
	      motorleft.write(36);
	      motorright.write(36);
	      break;
	    default:
	      // default case is if everything above fails
	      break;
	  }
	  return result;
	 }




#include<Servo.h>

//comment
  int testinput = 0;
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
  
  Servo servoarray [] = {Myservo1, Myservo2, Myservo3,Myservo4,Myservo5,Myservo6,Myservo7,Myservo8,Myservo9,Myservo10};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Myservo1.attach(2);
  Myservo2.attach(3);
  Myservo3.attach(4);
  Myservo4.attach(5);
  Myservo5.attach(6);
  Myservo6.attach(7);
  Myservo7.attach(8);
  Myservo8.attach(9);
  Myservo9.attach(10);
  Myservo10.attach(11);

  Servo servoarray[] = {Myservo1, Myservo2,Myservo3, Myservo4,Myservo5 , Myservo6,Myservo7,Myservo8,Myservo9,Myservo10}; 


  
}

void loop() {
  testinput = (testinput + 45)%90; 
  Myservo1.write(testinput);
  Myservo2.write(testinput);
  Myservo3.write(testinput);
  Myservo4.write(testinput);
  Myservo5.write(testinput);
  Myservo6.write(testinput);
  Serial.println("loop");
  delay(1000);

}







//motor char comparison
void Compare(char x, Servo motorleft, Servo motorright){
	int upper;
	int middle;
	int lower;
	int upper_middle;
	int upper_lower;
	int middle_lower;
	int no_dots;
	int all;
  switch (x) {
		    case ' ':
		      // this is space mapped to the empty cell
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case '!':
		      //'!' -> '⠮'
		      motorleft.write(middle_lower);
		      motorright.write(middle);
		      break;
		    case '"':
		      //'"' -> '⠐'
		      motorleft.write(middle_lower);
		      motorright.write(lower);
		      break;
		    case '#':
		      //'#' -> '⠼' 
		      motorleft.write(upper);
		      motorright.write(all);
		      break;
		    case '$': 
		      //'$' -> '⠫'
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case '%':
		      //'%' -> '⠩'
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case '&':
		      //'&' ->'⠯'
		      motorleft.write(all);
		      motorright.write(upper_lower);
		      break;
		    case'\uupperupper27':
		      //''' ->'⠄'
		      motorleft.write(middle_lower);
		      motorright.write(lower);
		      break;
		    case '(':
		      //'(' ->'⠷'
		      motorleft.write(all);
		      motorright.write(middle_lower);
		      break;
		    case ')':
		      //')' ->'⠾'
		      motorleft.write(middle_lower);
		      motorright.write(all);
		      break;
		    case '*':
		      //'*' ->'⠡'
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case '+':
		      //'+' ->'⠬'
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case ',':
		      //',' ->'⠠'
		      motorleft.write(middle);
		      motorright.write(no_dots);
		      break;
		    case '-':
		      //'-' ->'⠤'
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case '.':
		      //'.' ->'⠨'
		      motorleft.write(middle);
		      motorright.write(middle_lower);
		      break;
		    case '/':
		      //'/' ->'⠌'
		      motorleft.write(lower);
		      motorright.write(upper);
		      break;
		    case 'upper':
		      //'upper' ->'⠴'
		      motorleft.write(middle);
		      motorright.write(upper_middle);
		      break;
		    case '1':
		      //'1' ->'⠂'
		      motorleft.write(upper);
		      motorright.write(no_dots);
		      break;
		    case '2':
		      //'2' ->'⠆'
		      motorleft.write(upper_middle);
		      motorright.write(no_dots);
		      break;
		    case '3':
		      //'3' ->'⠒'
		      motorleft.write(upper);
		      motorright.write(upper);
		      break;
		    case '4':
		      //'4' ->'⠲'
		      motorleft.write(upper);
		      motorright.write(upper_middle);
		      break;
		    case '5':
		      //'5' ->'⠢'
		      motorleft.write(upper);
		      motorright.write(middle);
		      break;
		    case '6':
		      //'6' ->'⠖'
		      motorleft.write(upper_middle);
		      motorright.write(upper);
		      break;
		    case '7':
		      //'7' ->'⠶'
		      motorleft.write(upper_middle);
		      motorright.write(upper_middle);
		      break;
		    case '8':
		      //'8' ->'⠦'
		      motorleft.write(upper_middle);
		      motorright.write(middle);
		      break;
		    case '9':
		      //'9' ->'⠔'
		      motorleft.write(middle);
		      motorright.write(upper);
		      break;
		    case ':':
		      //':' ->'⠱'
		      motorleft.write(middle);
		      motorright.write(middle);
		      break;
		    case ';':
		      //';' ->'⠰'
		      motorleft.write(middle_lower);
		      motorright.write(no_dots);
		      break;
		    case '<':
		      //'<' ->'⠣'
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case '=':
		      //'=' ->'⠿'
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case '>':
		      //'>' ->'⠜'
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case '?':
		      //'?' ->'⠹'
		      motorleft.write(middle_lower);
		      motorright.write(lower);
		      break;
		    case '@':
		      //'@' ->'⠈'
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case 'A':
		      //'A' ->'⠁'
		      motorleft.write(upper);
		      motorright.write(no_dots);
		      break;
		    case 'B':
		      //'B' ->'⠃'
		      motorleft.write(upper_middle);
		      motorright.write(no_dots);
		      break;
		    case 'C':
		      //'C' ->'⠉'
		      motorleft.write(upper);
		      motorright.write(upper);
		      break;
		    case 'D':
		      //'D' ->'⠙'
		      motorleft.write(upper);
		      motorright.write(upper_middle);
		      break;
		    case 'E':
		      //'E' ->'⠑'
		      motorleft.write(upper);
		      motorright.write(middle);
		      break;
		    case 'F':
		      //'F' ->'⠋'
		      motorleft.write(upper_middle);
		      motorright.write(upper);
		      break;
		    case 'G':
		      //'G' ->'⠛'
		      motorleft.write(upper_middle);
		      motorright.write(upper_middle);
		      break;
		    case 'H':
		      //'H' ->'⠓'
		      motorleft.write(upper_middle);
		      motorright.write(middle);
		      break;
		    case 'I':
		      //'I' ->'⠊'
		      motorleft.write(middle);
		      motorright.write(upper);
		      break;
		    case 'J':
		      //'J' ->'⠚'
		      motorleft.write(middle);
		      motorright.write(upper_middle);
		      break;
		    case 'K':
		      //'K' ->'⠅'
		      motorleft.write(upper_lower);
		      motorright.write(no_dots);
		      break;
		    case 'L':
		      //'L' ->'⠇'
		      motorleft.write(all);
		      motorright.write(no_dots);
		      break;
		    case 'M':
		      //'M' ->'⠍'
		      motorleft.write(upper_lower);
		      motorright.write(upper);
		      break;
		    case 'N':
		      //'N' ->'⠝'
		      motorleft.write(upper_lower);
		      motorright.write(upper_middle);
		      break;
		    case 'O':
		      //'O' ->'⠕'
		      motorleft.write(upper_lower);
		      motorright.write(middle);
		      break;
		    case 'P':
		      //'P' ->'⠏'
		      motorleft.write(all);
		      motorright.write(upper);
		      break;
		    case 'Q':
		      //'Q' ->'⠟'
		      motorleft.write(all);
		      motorright.write(upper_middle);
		      break;
		    case 'R':
		      //'R' ->'⠗'
		      motorleft.write(all);
		      motorright.write(middle);
		      break;
		    case 'S':
		      //'S' ->'⠎'
		      motorleft.write(middle_lower);
		      motorright.write(upper);
		      break;
		    case 'T':
		      //'T' ->'⠞'
		      motorleft.write(middle_lower);
		      motorright.write(upper_middle);
		      break;
		    case 'U':
		      //'U' ->'⠥'
		      motorleft.write(upper_lower);
		      motorright.write(no_dots);
		      break;
		    case 'V':
		      //'V' ->'⠧'
		      motorleft.write(all);
		      motorright.write(no_dots);
		      break;
		    case 'W':
		      //'W' ->'⠺'
		      motorleft.write(middle);
		      motorright.write(all);
		      break;
		    case 'X':
		      //'X' ->'⠭'
		      motorleft.write(upper_lower);
		      motorright.write(upper_lower);
		      break;
		    case 'Y':
		      //'Y' ->'⠽'
		      motorleft.write(upper_lower);
		      motorright.write(all);
		      break;
		    case 'Z':
		      //'Z' ->'⠵'
		      motorleft.write(upper_lower);
		      motorright.write(middle_lower);
		      break;
		    case ']':
		      //']' ->'⠻'
		      motorleft.write(middle_lower);
		      motorright.write(middle_lower);
		      break;
		    case '[':
		      //'[' ->'⠪'
		      motorleft.write(middle_lower);
		      motorright.write(middle_lower);
		      break;
		    case '\uupperupper5c':
		      //'\' ->'⠌'
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case '^':
		      //'^' ->'⠘'
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case '_':
		      //'_' ->'⠸⠸'
		      motorleft.write(lower);
		      motorright.write(lower);
		      break;
		    default:
		      // default case is if everything above fails
		      break;
		  }
		 }


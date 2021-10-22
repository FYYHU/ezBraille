
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

//just define the switch case here don't bother about the rest
//note each case must be with with single quotation mark. i.e. 'k' not "k", double quotation will be treated as a string.


//for (int i = 0; i < 5; i++){
//    filesyst.read5();
//    Compare(filesyst.current[i],servoarray[i],servoarray[i+5]);
//}



//motor char comparison
void Compare(char x, Servo motorleft, Servo motorright){
  switch (x) {
		    case ' ':
		      // this is space mapped to the empty cell
		      motorleft.write(no dots);
		      motorright.write(no dots);
		      break;
		    case '!':
		      //'!' -> '⠮'
		      motorleft.write(middle lower);
		      motorright.write(middle);
		      break;
		    case '"':
		      //'"' -> '⠐'
		      motorleft.write(middle lower);
		      motorright.write(lower);
		      break;
		    case '#':
		      //'#' -> '⠼' 
		      motorleft.write(upper);
		      motorright.write(all);
		      break;
		    case '$': 
		      //'$' -> '⠫'
		      motorleft.write(no dots);
		      motorright.write(no dots);
		      break;
		    case '%':
		      //'%' -> '⠩'
		      motorleft.write(no dots);
		      motorright.write(no dots);
		      break;
		    case '&':
		      //'&' ->'⠯'
		      motorleft.write(all);
		      motorright.write(upper lower);
		      break;
		    case'\uupperupper27':
		      //''' ->'⠄'
		      motorleft.write(middle lower);
		      motorright.write(lower);
		      break;
		    case '(':
		      //'(' ->'⠷'
		      motorleft.write(all);
		      motorright.write(middle lower);
		      break;
		    case ')':
		      //')' ->'⠾'
		      motorleft.write(middle lower);
		      motorright.write(all);
		      break;
		    case '*':
		      //'*' ->'⠡'
		      motorleft.write(no dots);
		      motorright.write(no dots);
		      break;
		    case '+':
		      //'+' ->'⠬'
		      motorleft.write(no dots);
		      motorright.write(no dots);
		      break;
		    case ',':
		      //',' ->'⠠'
		      motorleft.write(middle);
		      motorright.write(no dots);
		      break;
		    case '-':
		      //'-' ->'⠤'
		      motorleft.write(no dots);
		      motorright.write(no dots);
		      break;
		    case '.':
		      //'.' ->'⠨'
		      motorleft.write(middle);
		      motorright.write(middle lower);
		      break;
		    case '/':
		      //'/' ->'⠌'
		      motorleft.write(lower);
		      motorright.write(upper);
		      break;
		    case 'upper':
		      //'upper' ->'⠴'
		      motorleft.write(middle);
		      motorright.write(upper middle);
		      break;
		    case '1':
		      //'1' ->'⠂'
		      motorleft.write(upper);
		      motorright.write(no dots);
		      break;
		    case '2':
		      //'2' ->'⠆'
		      motorleft.write(upper middle);
		      motorright.write(no dots);
		      break;
		    case '3':
		      //'3' ->'⠒'
		      motorleft.write(upper);
		      motorright.write(upper);
		      break;
		    case '4':
		      //'4' ->'⠲'
		      motorleft.write(upper);
		      motorright.write(upper middle);
		      break;
		    case '5':
		      //'5' ->'⠢'
		      motorleft.write(upper);
		      motorright.write(middle);
		      break;
		    case '6':
		      //'6' ->'⠖'
		      motorleft.write(upper middle);
		      motorright.write(upper);
		      break;
		    case '7':
		      //'7' ->'⠶'
		      motorleft.write(upper middle);
		      motorright.write(upper middle);
		      break;
		    case '8':
		      //'8' ->'⠦'
		      motorleft.write(upper middle);
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
		      motorleft.write(middle lower);
		      motorright.write(no dots);
		      break;
		    case '<':
		      //'<' ->'⠣'
		      motorleft.write(no dots);
		      motorright.write(no dots);
		      break;
		    case '=':
		      //'=' ->'⠿'
		      motorleft.write(no dots);
		      motorright.write(no dots);
		      break;
		    case '>':
		      //'>' ->'⠜'
		      motorleft.write(no dots);
		      motorright.write(no dots);
		      break;
		    case '?':
		      //'?' ->'⠹'
		      motorleft.write(middle lower);
		      motorright.write(lower);
		      break;
		    case '@':
		      //'@' ->'⠈'
		      motorleft.write(no dots);
		      motorright.write(no dots);
		      break;
		    case 'A':
		      //'A' ->'⠁'
		      motorleft.write(upper);
		      motorright.write(no dots);
		      break;
		    case 'B':
		      //'B' ->'⠃'
		      motorleft.write(upper middle);
		      motorright.write(no dots);
		      break;
		    case 'C':
		      //'C' ->'⠉'
		      motorleft.write(upper);
		      motorright.write(upper);
		      break;
		    case 'D':
		      //'D' ->'⠙'
		      motorleft.write(upper);
		      motorright.write(upper middle);
		      break;
		    case 'E':
		      //'E' ->'⠑'
		      motorleft.write(upper);
		      motorright.write(middle);
		      break;
		    case 'F':
		      //'F' ->'⠋'
		      motorleft.write(upper middle);
		      motorright.write(upper);
		      break;
		    case 'G':
		      //'G' ->'⠛'
		      motorleft.write(upper middle);
		      motorright.write(upper middle);
		      break;
		    case 'H':
		      //'H' ->'⠓'
		      motorleft.write(upper middle);
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
		      motorright.write(upper middle);
		      break;
		    case 'K':
		      //'K' ->'⠅'
		      motorleft.write(upper lower);
		      motorright.write(no dots);
		      break;
		    case 'L':
		      //'L' ->'⠇'
		      motorleft.write(all);
		      motorright.write(no dots);
		      break;
		    case 'M':
		      //'M' ->'⠍'
		      motorleft.write(upper lower);
		      motorright.write(upper);
		      break;
		    case 'N':
		      //'N' ->'⠝'
		      motorleft.write(upper lower);
		      motorright.write(upper middle);
		      break;
		    case 'O':
		      //'O' ->'⠕'
		      motorleft.write(upper lower);
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
		      motorright.write(upper middle);
		      break;
		    case 'R':
		      //'R' ->'⠗'
		      motorleft.write(all);
		      motorright.write(middle);
		      break;
		    case 'S':
		      //'S' ->'⠎'
		      motorleft.write(middle lower);
		      motorright.write(upper);
		      break;
		    case 'T':
		      //'T' ->'⠞'
		      motorleft.write(middle lower);
		      motorright.write(upper middle);
		      break;
		    case 'U':
		      //'U' ->'⠥'
		      motorleft.write(upper lower);
		      motorright.write(no dots);
		      break;
		    case 'V':
		      //'V' ->'⠧'
		      motorleft.write(all);
		      motorright.write(no dots);
		      break;
		    case 'W':
		      //'W' ->'⠺'
		      motorleft.write(middle);
		      motorright.write(all);
		      break;
		    case 'X':
		      //'X' ->'⠭'
		      motorleft.write(upper lower);
		      motorright.write(upper lower);
		      break;
		    case 'Y':
		      //'Y' ->'⠽'
		      motorleft.write(upper lower);
		      motorright.write(all);
		      break;
		    case 'Z':
		      //'Z' ->'⠵'
		      motorleft.write(upper lower);
		      motorright.write(middle lower);
		      break;
		    case ']':
		      //']' ->'⠻'
		      motorleft.write(middle lower);
		      motorright.write(middle lower);
		      break;
		    case '[':
		      //'[' ->'⠪'
		      motorleft.write(middle lower);
		      motorright.write(middle lower);
		      break;
		    case '\uupperupper5c':
		      //'\' ->'⠌'
		      motorleft.write(no dots);
		      motorright.write(no dots);
		      break;
		    case '^':
		      //'^' ->'⠘'
		      motorleft.write(no dots);
		      motorright.write(no dots);
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


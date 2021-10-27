//This is the main code where we will put each component

#include <SPI.h>
#include <SD.h>
#include<Servo.h>


//class has to be created before object can be created
//FileSyst class manages the files

 class FileSyst {
    private:
      int counter_files = 0; //use counter when toggling
      int Number_files = 3; //number of files read from SD
      int char_read_count = 5;
      File Reading;
    protected:
      File root = SD.open("/");
      String SDFile1;
      String SDFile2;
      String SDFile3;
    public:
      //5 character cache
      //init with empty array
      boolean end_file_flag = false;//track if we are end of file
      char Current_Line[5]= {' ',' ',' ',' ',' '};

      //File track;
      String Current_File;
      String File_List[3];
      FileSyst() {//constructor
        
      //loop over the 3 first files (we skip file 1) and store the 3 file names
        for (int i = 0; i < Number_files + 1; i++) {
          File entry =  root.openNextFile();
          if (! entry) {
            // no more files
            break;
          }
          else if (i == 0){
            Serial.println("skipped");
            //skip .DAT file
          } 
          else if (i == 1)
            {
              Serial.println(entry.name());
              SDFile1 = entry.name();
            }
          else if (i == 2)
          {
            Serial.println(entry.name());
            SDFile2 = entry.name();
          }
          else if (i == 3)
          {
            Serial.println(entry.name());
            SDFile3 = entry.name();
          }
        }
        //init list
        File_List[0] = SDFile1;
        File_List[1] = SDFile2;
        File_List[2] = SDFile3;
        //open the first file
        Reading = SD.open(File_List[0]);
      }

      //TODO create method to toggle Files
      void Toggle_File(){
        //close current open file
        Reading.close();
        //assign new file to current
        counter_files = (counter_files + 1)% Number_files;
        Current_File = File_List[counter_files];
        Serial.print("we toggle and are now reading");
        Serial.println(File_List[counter_files]);
        //reopen
        Reading = SD.open(Current_File);
        end_file_flag = false;//reset end_file_flag
      }
      //TODO create method to Read file and return char
      //Read char from file assumes file is open
      char Read_current(){
        if (Reading.available()) {
            return Reading.read();
        }else{
          //done reading
          //set end file flag
          end_file_flag = true;
          return ' ';
        }
      }
      //read next 5 char
      void Read_next_line(){
        for (int i = 0; i < char_read_count;i++){
          Current_Line[i] = Read_current();
        }
        Serial.print("location ");
        Serial.println(Reading.position());
        
        
      }
      //previous 5 characters
      void Read_prev_line(){
        unsigned long location = Reading.position()-2*char_read_count;//reader goes to 5 characters before previous
        boolean checker = Reading.seek(location);
          if (checker){
            Serial.println("prevexist");
            for (int i = 0; i < char_read_count;i++){
            Current_Line[i] = Read_current();
            }
          }
          else{
            //note this means prev is interval before [0,5] we now reset to default state;
            Reading.seek(0);
            for (int i = 0; i < char_read_count;i++){
            Current_Line[i] = Read_current();
            }
            Serial.println("at [0,5]");
         }
         Serial.print("location ");
         Serial.println(Reading.position());
         end_file_flag = false;//reset end of file flag;
      }

  };


//global variables:
int SDCardPin = 53;
//true if auto read on
boolean auto_read = true;
//button values
int Toggle_value = 0;
int Next_value = 0;
int Prev_value = 0;
int Touch_Sensor_value = 0;
int Auto_read_value = 0;
//button pin
int Pin_prev = 22;   //Pin for prev button
int Pin_next = 24; //Pin for next button
int Pin_toggle = 26;   // choose the input pin toggle file
int Pin_auto = 28; //choose input pin for toggle auto read
int Touch_Sensor_Pin = 36;

//motor variables
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
//servo array
Servo Servoarray[] = {Myservo1, Myservo3, Myservo5,Myservo7,Myservo9,Myservo2,Myservo4,Myservo6,Myservo8,Myservo10};

FileSyst* FileSystemSD;// global pointer to FileSystem Object



void setup() {
    // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(SDCardPin)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  Serial.println("done!");

  //now we can assign FileSys object to our pointer
  FileSystemSD = new FileSyst();

  //attach pin to motor
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
  //setup button pins
  pinMode(Touch_Sensor_Pin, INPUT);
  pinMode(Pin_prev, INPUT);
  pinMode(Pin_next, INPUT);
  pinMode(Pin_toggle, INPUT);

}

void loop() {

    //Set base button values 
    Next_value = 0;  
    Prev_value = 0;

    //read text in Current_Line
    for (int i = 0; i < 5; i++){
        Serial.print(FileSystemSD->Current_Line[i]);//accesses the Current_Line array
		Compare(FileSystemSD->Current_Line[i],Servoarray[i],Servoarray[i+5]);
    }
    


    //BUTTON Loop
    while(true){
        Toggle_value = digitalRead(Pin_toggle);  // read toggle button input
        Next_value = digitalRead(Pin_next);  // read next button input
        Prev_value = digitalRead(Pin_prev); // read prev button input
		Touch_Sensor_value = digitalRead(Touch_Sensor_Pin);// read touch sensor input
		Auto_read_value = digitalRead(Pin_auto);
        if (Toggle_value == HIGH) {         // check if the input is HIGH (button released)
            FileSystemSD->Toggle_File();
            break; //break out of loop
        } else if (Next_value == HIGH){
            //read_next
            Serial.println("next");
            // To access methods and var in our class from a pointer we need to use ->
            FileSystemSD->Read_next_line();// calls the Read_next_line() method
            break;
        } else if (Prev_value == HIGH){
            //read_prev_line
            Serial.println("prev");
            FileSystemSD->Read_prev_line();
            break;
        } else if (Touch_Sensor_value == HIGH && auto_read){
          //read_next
          Serial.println("touchsens");
          Serial.println("next");
          // To access methods and var in our class from a pointer we need to use ->
          FileSystemSD->Read_next_line();// calls the Read_next_line() method
          delay(250);
          break;
        } else if (Auto_read_value == HIGH){
			    auto_read = !auto_read;
          Serial.println("autoread toggle");
          delay(1000);
		}

    }
    
    Serial.println("Waiting");
    delay(1000);                // waits for 1 second
  
}


//motor char comparison
void Compare(char x, Servo motorleft, Servo motorright){
	int no_dots = 0;
	int upper = 18;
	int middle = 36;
	int lower = 54;
	int upper_lower = 72;
  	int upper_middle = 90;
	int middle_lower = 108;
  	int all = 126;
	

  switch (x) {
		    case ' ':
		      // this is space mapped to the empty cell
		      motorleft.write(no_dots);
		      motorright.write(no_dots);
		      break;
		    case '!':
		      //'!' -> '⠁'
		      motorleft.write(upper);
		      motorright.write(no_dots);
		      break;
		    case '"':
		      //'"' -> '⠂'
		      motorleft.write(middle);
		      motorright.write(no_dots);
		      break;
		    case '#':
		      //'#' -> '⠃' 
		      motorleft.write(upper_middle);
		      motorright.write(no_dots);
		      break;
		    case '$': 
		      //'$' -> '⠄'
		      motorleft.write(lower);
		      motorright.write(no_dots);
		      break;
		    case '%':
		      //'%' -> '⠅'
		      motorleft.write(upper_lower);
		      motorright.write(no_dots);
		      break;
		    case '&':
		      //'&' ->'⠆'
		      motorleft.write(middle_lower);
		      motorright.write(no_dots);
		      break;
		    case '\u0027':
		      //''' ->'⠇'
		      motorleft.write(all);
		      motorright.write(no_dots);
		      break;
		    case '(':
		      //'(' ->'⠈'
		      motorleft.write(no_dots);
		      motorright.write(upper);
		      break;
		    case ')':
		      //')' ->'⠉'
		      motorleft.write(upper);
		      motorright.write(upper);
		      break;
		    case '*':
		      //'*' ->'⠊'
		      motorleft.write(middle);
		      motorright.write(upper);
		      break;
		    case '+':
		      //'+' ->'⠋'
		      motorleft.write(upper_middle);
		      motorright.write(upper);
		      break;
		    case ',':
		      //',' ->'⠌'
		      motorleft.write(lower);
		      motorright.write(upper);
		      break;
		    case '-':
		      //'-' ->'⠍'
		      motorleft.write(upper_lower);
		      motorright.write(upper);
		      break;
		    case '.':
		      //'.' ->'⠎'
		      motorleft.write(middle_lower);
		      motorright.write(upper);
		      break;
		    case '/':
		      //'/' ->'⠏'
		      motorleft.write(all);
		      motorright.write(upper);
		      break;
		    case '0':
		      //'upper' ->'⠐'
		      motorleft.write(no_dots);
		      motorright.write(middle);
		      break;
		    case '1':
		      //'1' ->'⠑'
		      motorleft.write(upper);
		      motorright.write(middle);
		      break;
		    case '2':
		      //'2' ->'⠒'
		      motorleft.write(middle);
		      motorright.write(middle);
		      break;
		    case '3':
		      //'3' ->'⠓'
		      motorleft.write(upper_middle);
		      motorright.write(middle);
		      break;
		    case '4':
		      //'4' ->'⠔'
		      motorleft.write(lower);
		      motorright.write(middle);
		      break;
		    case '5':
		      //'5' ->'⠕'
		      motorleft.write(upper_lower);
		      motorright.write(middle);
		      break;
		    case '6':
		      //'6' ->'⠖'
		      motorleft.write()middle_lower;
		      motorright.write(middle);
		      break;
		    case '7':
		      //'7' ->'⠗'
		      motorleft.write(all);
		      motorright.write(middle);
		      break;
		    case '8':
		      //'8' ->'⠘'
		      motorleft.write(no_dots);
		      motorright.write(upper_middle);
		      break;
		    case '9':
		      //'9' ->'⠙'
		      motorleft.write(upper);
		      motorright.write(upper_middle);
		      break;
		    case ':':
		      //':' ->'⠚'
		      motorleft.write(middle);
		      motorright.write(upper_middle);
		      break;
		    case ';':
		      //';' ->'⠛'
		      motorleft.write(upper_lower);
		      motorright.write(upper_lower);
		      break;
		    case '<':
		      //'<' ->'⠜'
		      motorleft.write(lower);
		      motorright.write(upper_middle);
		      break;
		    case '=':
		      //'=' ->'⠝'
		      motorleft.write(upper_lower);
		      motorright.write(upper_middle);
		      break;
		    case '>':
		      //'>' ->'⠞'
		      motorleft.write(middle_lower);
		      motorright.write(upper_middle);
		      break;
		    case '?':
		      //'?' ->'⠟'
		      motorleft.write(all);
		      motorright.write(upper_middle);
		      break;
		    case '@':
		      //'@' ->'⠠'
		      motorleft.write(no_dots);
		      motorright.write(lower);
		      break;
		    case 'A':
		      //'A' ->'⠡'
		      motorleft.write(upper);
		      motorright.write(lower);
		      break;
		    case 'B':
		      //'B' ->'⠢'
		      motorleft.write(middle);
		      motorright.write(lower);
		      break;
		    case 'C':
		      //'C' ->'⠣'
		      motorleft.write(upper_middle);
		      motorright.write(lower);
		      break;
		    case 'D':
		      //'D' ->'⠤'
		      motorleft.write(lower);
		      motorright.write(lower);
		      break;
		    case 'E':
		      //'E' ->'⠥'
		      motorleft.write(upper_lower);
		      motorright.write(lower;
		      break;
		    case 'F':
		      //'F' ->'⠦'
		      motorleft.write(middle_lower);
		      motorright.write(lower);
		      break;
		    case 'G':
		      //'G' ->'⠧'
		      motorleft.write(all);
		      motorright.write(lower);
		      break;
		    case 'H':
		      //'H' ->'⠨'
		      motorleft.write(no_dots);
		      motorright.write(upper_lower);
		      break;
		    case 'I':
		      //'I' ->'⠩'
		      motorleft.write(upper);
		      motorright.write(upper_lower);
		      break;
		    case 'J':
		      //'J' ->'⠪'
		      motorleft.write(middle);
		      motorright.write(upper_lower);
		      break;
		    case 'K':
		      //'K' ->'⠫'
		      motorleft.write(upper_middle);
		      motorright.write(upper_lower);
		      break;
		    case 'L':
		      //'L' ->'⠬'
		      motorleft.write(lower);
		      motorright.write(upper_lower);
		      break;
		    case 'M':
		      //'M' ->'⠭'
		      motorleft.write(upper_lower);
		      motorright.write(upper_lower);
		      break;
		    case 'N':
		      //'N' ->'⠮'
		      motorleft.write(middle_lower);
		      motorright.write(upper_lower);
		      break;
		    case 'O':
		      //'O' ->'⠯'
		      motorleft.write(all);
		      motorright.write(upper_lower);
		      break;
		    case 'P':
		      //'P' ->'⠰'
		      motorleft.write(no_dots);
		      motorright.write(middle_lower);
		      break;
		    case 'Q':
		      //'Q' ->'⠱'
		      motorleft.write(upper);
		      motorright.write(middle_lower);
		      break;
		    case 'R':
		      //'R' ->'⠲'
		      motorleft.write(middle);
		      motorright.write(middle_lower);
		      break;
		    case 'S':
		      //'S' ->'⠳'
		      motorleft.write(upper_middle);
		      motorright.write(middle_lower);
		      break;
		    case 'T':
		      //'T' ->'⠴'
		      motorleft.write(lower);
		      motorright.write(middle_lower);
		      break;
		    case 'U':
		      //'U' ->'⠵'
		      motorleft.write(upper_lower);
		      motorright.write(middle_lower);
		      break;
		    case 'V':
		      //'V' ->'⠶'
		      motorleft.write(middle_lower);
		      motorright.write(middle_lower);
		      break;
		    case 'W':
		      //'W' ->'⠷'
		      motorleft.write(all);
		      motorright.write(middle_lower);
		      break;
		    case 'X':
		      //'X' ->'⠸'
		      motorleft.write(no_dots);
		      motorright.write(all);
		      break;
		    case 'Y':
		      //'Y' ->'⠹'
		      motorleft.write(upper);
		      motorright.write(all);
		      break;
		    case 'Z':
		      //'Z' ->'⠺'
		      motorleft.write(middle);
		      motorright.write(all);
		      break;
		    case '[':
		      //'[' ->'⠻'
		      motorleft.write(upper_middle);
		      motorright.write(all);
		      break;
		    case '\u005c':
		      //'\' ->'⠼'
		      motorleft.write(lower);
		      motorright.write(all);
		      break;
			case ']':
		      //']' ->'⠽'
		      motorleft.write(upper_lower);
		      motorright.write(all);
		      break;
		    case '^':
		      //'^' ->'⠾'
		      motorleft.write(middle_lower);
		      motorright.write(all);
		      break;
		    case '_':
		      //'_' ->'⠿'
		      motorleft.write(all);
		      motorright.write(all);
		      break;
		    default:
		      // default case is if everything above fails
		      break;
		  }
		 }

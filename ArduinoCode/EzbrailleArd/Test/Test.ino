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


char testarray[] = {'A','B','C','D','E','F','G', 'H', 'I', 'J'};
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
int Pin_toggle = 26;   // choose the input pin (for a pushbutton)
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
Servo Servoarray[] = {Myservo1, Myservo2, Myservo3,Myservo4,Myservo5,Myservo6,Myservo7,Myservo8,Myservo9,Myservo10};

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
  //FileSystemSD = new FileSyst();

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
        Serial.print(testarray[i]);//accesses the Current_Line array
		Compare(testarray[i],Servoarray[i],Servoarray[i+5]);
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
          delay(1000);
          break;
        } else if (Auto_read_value == HIGH){
			auto_read = !auto_read;
		}

    }
    
    Serial.println("Waiting");
    delay(1000);                // waits for 1 second
  
}


//motor char comparison
int Compare(char x, Servo motorleft, Servo motorright){
  int result;
  switch (x) {
	    case ' ':
	      // this is space mapped to the empty cell
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '!':
	      //'!' -> '???'
	      motorleft.write(108);
	      motorright.write(18);
	      break;
	    case '"':
	      //'"' -> '???'
	      motorleft.write(108);
	      motorright.write(36);
	      break;
	    case '#':
	      //'#' -> '???' 
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '$': 
	      //'$' -> '???'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '%':
	      //'%' -> '???'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '&':
	      //'&' ->'???'
	      motorleft.write(72);
	      motorright.write(120);
	      break;
	    case'\u0027':
	      //''' ->'???'
	      motorleft.write(108);
	      motorright.write(36);
	      break;
	    case '(':
	      //'(' ->'???'
	      motorleft.write(72);
	      motorright.write(108);
	      break;
	    case ')':
	      //')' ->'???'
	      motorleft.write(108);
	      motorright.write(72);
	      break;
	    case '*':
	      //'*' ->'???'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '+':
	      //'+' ->'???'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case ',':
	      //',' ->'???'
	      motorleft.write(18);
	      motorright.write(54);
	      break;
	    case '-':
	      //'-' ->'???'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '.':
	      //'.' ->'???'
	      motorleft.write(18);
	      motorright.write(108);
	      break;
	    case '/':
	      //'/' ->'???'
	      motorleft.write(36);
	      motorright.write(0);
	      break;
	    case '0':
	      //'0' ->'???'
	      motorleft.write(18);
	      motorright.write(90);
	      break;
	    case '1':
	      //'1' ->'???'
	      motorleft.write(0);
	      motorright.write(54);
	      break;
	    case '2':
	      //'2' ->'???'
	      motorleft.write(90);
	      motorright.write(54);
	      break;
	    case '3':
	      //'3' ->'???'
	      motorleft.write(0);
	      motorright.write(0);
	      break;
	    case '4':
	      //'4' ->'???'
	      motorleft.write(0);
	      motorright.write(90);
	      break;
	    case '5':
	      //'5' ->'???'
	      motorleft.write(0);
	      motorright.write(18);
	      break;
	    case '6':
	      //'6' ->'???'
	      motorleft.write(90);
	      motorright.write(0);
	      break;
	    case '7':
	      //'7' ->'???'
	      motorleft.write(90);
	      motorright.write(90);
	      break;
	    case '8':
	      //'8' ->'???'
	      motorleft.write(90);
	      motorright.write(18);
	      break;
	    case '9':
	      //'9' ->'???'
	      motorleft.write(18);
	      motorright.write(0);
	      break;
	    case ':':
	      //':' ->'???'
	      motorleft.write(18);
	      motorright.write(18);
	      break;
	    case ';':
	      //';' ->'???'
	      motorleft.write(108);
	      motorright.write(54);
	      break;
	    case '<':
	      //'<' ->'???'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '=':
	      //'=' ->'???'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '>':
	      //'>' ->'???'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '?':
	      //'?' ->'???'
	      motorleft.write(108);
	      motorright.write(36);
	      break;
	    case '@':
	      //'@' ->'???'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case 'A':
	      //'A' ->'???'
	      motorleft.write(0);
	      motorright.write(54);
	      break;
	    case 'B':
	      //'B' ->'???'
	      motorleft.write(90);
	      motorright.write(54);
	      break;
	    case 'C':
	      //'C' ->'???'
	      motorleft.write(0);
	      motorright.write(0);
	      break;
	    case 'D':
	      //'D' ->'???'
	      motorleft.write(0);
	      motorright.write(90);
	      break;
	    case 'E':
	      //'E' ->'???'
	      motorleft.write(0);
	      motorright.write(18);
	      break;
	    case 'F':
	      //'F' ->'???'
	      motorleft.write(90);
	      motorright.write(0);
	      break;
	    case 'G':
	      //'G' ->'???'
	      motorleft.write(90);
	      motorright.write(90);
	      break;
	    case 'H':
	      //'H' ->'???'
	      motorleft.write(90);
	      motorright.write(18);
	      break;
	    case 'I':
	      //'I' ->'???'
	      motorleft.write(18);
	      motorright.write(0);
	      break;
	    case 'J':
	      //'J' ->'???'
	      motorleft.write(18);
	      motorright.write(90);
	      break;
	    case 'K':
	      //'K' ->'???'
	      motorleft.write(120);
	      motorright.write(54);
	      break;
	    case 'L':
	      //'L' ->'???'
	      motorleft.write(72);
	      motorright.write(54);
	      break;
	    case 'M':
	      //'M' ->'???'
	      motorleft.write(120);
	      motorright.write(0);
	      break;
	    case 'N':
	      //'N' ->'???'
	      motorleft.write(120);
	      motorright.write(90);
	      break;
	    case 'O':
	      //'O' ->'???'
	      motorleft.write(120);
	      motorright.write(18);
	      break;
	    case 'P':
	      //'P' ->'???'
	      motorleft.write(72);
	      motorright.write(0);
	      break;
	    case 'Q':
	      //'Q' ->'???'
	      motorleft.write(72);
	      motorright.write(90);
	      break;
	    case 'R':
	      //'R' ->'???'
	      motorleft.write(72);
	      motorright.write(18);
	      break;
	    case 'S':
	      //'S' ->'???'
	      motorleft.write(108);
	      motorright.write(0);
	      break;
	    case 'T':
	      //'T' ->'???'
	      motorleft.write(108);
	      motorright.write(90);
	      break;
	    case 'U':
	      //'U' ->'???'
	      motorleft.write(120);
	      motorright.write(54);
	      break;
	    case 'V':
	      //'V' ->'???'
	      motorleft.write(72);
	      motorright.write(54);
	      break;
	    case 'W':
	      //'W' ->'???'
	      motorleft.write(18);
	      motorright.write(72);
	      break;
	    case 'X':
	      //'X' ->'???'
	      motorleft.write(120);
	      motorright.write(120);
	      break;
	    case 'Y':
	      //'Y' ->'???'
	      motorleft.write(120);
	      motorright.write(72);
	      break;
	    case 'Z':
	      //'Z' ->'???'
	      motorleft.write(120);
	      motorright.write(108);
	      break;
	    case ']':
	      //']' ->'???'
	      motorleft.write(108);
	      motorright.write(108);
	      break;
	    case '[':
	      //'[' ->'???'
	      motorleft.write(108);
	      motorright.write(108);
	      break;
	    case '\u005c':
	      //'\' ->'???'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '^':
	      //'^' ->'???'
	      motorleft.write(54);
	      motorright.write(54);
	      break;
	    case '_':
	      //'_' ->'??????'
	      motorleft.write(36);
	      motorright.write(36);
	      break;
	    default:
	      motorleft.write(54);
		  motorright.write(54);
	      break;
	  }
	  return result;
	 }

//This is the main code where we will put each component

#include <SPI.h>
#include <SD.h>
#include<Servo.h>


//class has to be created before object can be created
//FileSyst class manages the files
 class FileSyst {
    private:
      int counter_files = 0; //use counter when toggling
      int Number_files = 3;
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
        
      //loop over the 4 first files (we skip file 1) and store the 3 file names
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

//button values
int Toggle_value = 0;
int Next_value = 0;
int Prev_value = 0;

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
Servo[] servoarray = {Myservo1, Myservo2, Myservo3,Myservo4,Myservo5,Myservo6,Myservo7,Myservo8,Myservo9,Myservo10};

FileSyst* FileSystemSD;// global pointer to FileSystem Object



void setup() {
    // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  Serial.println("done!");

  //now we can assign FileSys object to our pointer
  FileSystemSD = new FileSyst();

  //attach pin to motor
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

}

void loop() {
    // To access methods and var in our class from a pointer we need to use ->
    FileSystemSD->Read_next_line();// calls the Read_next_line() method
    Serial.println("next");
    FileSystemSD->Read_next_line();
    Serial.println("next");
    FileSystemSD->Read_next_line();
    for (int i = 0; i < 5; i++){
        Serial.print(FileSystemSD->Current_Line[i]);//accesses the Current_Line array
    }
    


    //BUTTON Loop
    While(True){
        Toggle_value = digitalRead(Pin_toggle);  // read toggle button input
        Next_value = digitalRead(Pin_next);  // read next button input
        Prev_value = digitalRead(Pin_prev); // read prev button input
        if (Toggle_value == HIGH) {         // check if the input is HIGH (button released)
            //TOGGLE FILE
            break; //break out of loop
        } else if (Next_value == HIGH){
            //read_next
            break;
        } else if (Prev_value == HIGH){
            //read_prev_line
            break;
        }

    }


   delay(1000);                // waits for 1 second
  
}


//motor char comparison
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
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case '"':
      //'"' -> '⠐'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case '#':
      //'#' -> '⠼' 
      motorleft.write(angleleft);
      motorright.write(angleright);
      break
    case'$': 
      //'$' -> '⠫'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'%':
      //'%' -> '⠩'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'&':
      //'&' ->'⠯'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case''':
      //''' ->'⠄'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'(':
      //'(' ->'⠷'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case')':
      //')' ->'⠾'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'*':
      //'*' ->'⠡'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'+':
      //'+' ->'⠬'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case',':
      //',' ->'⠠'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'-':
      //'-' ->'⠤'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'.':
      //'.' ->'⠨'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'/':
      //'/' ->'⠌'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'0':
      //'0' ->'⠴'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'1':
      //'1' ->'⠂'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'2':
      //'2' ->'⠆'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'3':
      //'3' ->'⠒'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'4':
      //'4' ->'⠲'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'5':
      //'5' ->'⠢'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'6':
      //'6' ->'⠖'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'7':
      //'7' ->'⠶'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'8':
      //'8' ->'⠦'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'9':
      //'9' ->'⠔'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case':':
      //':' ->'⠱'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case';':
      //';' ->'⠰'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'<':
      //'<' ->'⠣'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'=':
      //'=' ->'⠿'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'>':
      //'>' ->'⠜'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'?':
      //'?' ->'⠹'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'@':
      //'@' ->'⠈'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'A':
      //'A' ->'⠁'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'B':
      //'B' ->'⠃'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'C':
      //'C' ->'⠉'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'D':
      //'D' ->'⠙'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'E':
      //'E' ->'⠑'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'F':
      //'F' ->'⠋'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'G':
      //'G' ->'⠛'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'H':
      //'H' ->'⠓'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'I':
      //'I' ->'⠊'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'J':
      //'J' ->'⠚'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'K':
      //'K' ->'⠅'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'L':
      //'L' ->'⠇'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'M':
      //'M' ->'⠍'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'N':
      //'N' ->'⠝'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'O':
      //'O' ->'⠕'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'P':
      //'P' ->'⠏'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'Q':
      //'Q' ->'⠟'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'R':
      //'R' ->'⠗'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'S':
      //'S' ->'⠎'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'T':
      //'T' ->'⠞'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'U':
      //'U' ->'⠥'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'V':
      //'V' ->'⠧'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'W':
      //'W' ->'⠺'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'X':
      //'X' ->'⠭'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'Y':
      //'Y' ->'⠽'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'Z':
      //'Z' ->'⠵'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case']':
      //']' ->'⠻'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'[':
      //'[' ->'⠪'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'/':
      //'/' ->'⠌'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'^':
      //'^' ->'⠘'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    case'_':
      //'_' ->'⠸⠸'
      motorleft.write(angleleft);
      motorright.write(angleright);
      break;
    default:
      // default case is if everything above fails
      break;
  }
  return result;
 }



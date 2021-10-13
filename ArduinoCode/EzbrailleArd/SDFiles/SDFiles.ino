/*
  Listfiles

  This example shows how print out the files in a
  directory on a SD card

  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  created   Nov 2010
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe
  modified 2 Feb 2014
  by Scott Fitzgerald

  This example code is in the public domain.

*/
#include <SPI.h>
#include <SD.h>


//Global variables


//6 character arrays
char prev[6];
char current[6];
char next[6];
//class has to be created before object is being created
//FileSyst class manages the files
 class FileSyst {
    private:
      int counter_files = 0; //use counter when toggling
      int Number_files = 3;
      File Reading;
    protected:
      File root = SD.open("/");
      String SDFile1;
      String SDFile2;
      String SDFile3;
    public:
      //6 character cache
      //init with empty array
      char Prev_Line[6]= {' ',' ',' ',' ',' ',' '};
      char Current_Line[6]= {' ',' ',' ',' ',' ',' '};
      char Next_Line[6]= {' ',' ',' ',' ',' ',' '};
      char temp[6] = {' ',' ',' ',' ',' ',' '}; //temporary array used in calc

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
      }
      //TODO create method to Read file and return char
      //Read char from file assumes file is open
      char Read_current(){
        if (Reading.available()) {
            return Reading.read();
        }else{
          //done reading
          return ' ';
        }
      }
      //read next six char
      void Read_next_six_char(){
        for (int i = 0; i < 6;i++){
          temp[i] = Read_current();
          //reassign each character
          Prev_Line[i] = Current_Line[i];
          Current_Line[i] = Next_Line[i];
          Next_Line[i] = temp[i];
        }
        Serial.print("location ");
        Serial.println(Reading.position());
        
        
      }
      //previous 6 characters
      void Read_prev_six_char(){
        unsigned long location = Reading.position()-18;
        boolean checker = Reading.seek(location);
          if (checker){
            Serial.println("prevexist");
            for (int i = 0; i < 6;i++){
            temp[i] = Read_current();
            Next_Line[i] = Current_Line[i];
            Current_Line[i] = Prev_Line[i];
            Prev_Line[i] = temp[i];
            }
          }
          else {
            //we reset back to start;
            Serial.println("prev not exist");
            Reading.seek(0);
            Read_next_six_char();
            }
         Serial.print("location ");
         Serial.println(Reading.position());
      }

  };

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

  
  FileSyst FileSystemSD;
  Serial.println("toggling");
  Serial.println("now system reading: ");
  Serial.println("next");
  FileSystemSD.Read_next_six_char();
  //Print text in current
  for (int i = 0; i < 6; i++){
    Serial.print(FileSystemSD.Current_Line[i]);
    }
     Serial.println("next");
  FileSystemSD.Read_next_six_char();
  //Print text in current
  for (int i = 0; i < 6; i++){
    Serial.print(FileSystemSD.Current_Line[i]);
    }
      Serial.println("next");
  FileSystemSD.Read_next_six_char();
  //Print text in current
  for (int i = 0; i < 6; i++){
    Serial.print(FileSystemSD.Current_Line[i]);
    }
      Serial.println("next");
  FileSystemSD.Read_next_six_char();
  //Print text in current
  for (int i = 0; i < 6; i++){
    Serial.print(FileSystemSD.Current_Line[i]);
    }
        Serial.println("prev");
  FileSystemSD.Read_prev_six_char();
  //Print text in current
  for (int i = 0; i < 6; i++){
    Serial.print(FileSystemSD.Current_Line[i]);
    }
      Serial.println("prev");
  FileSystemSD.Read_prev_six_char();
  //Print text in current
  for (int i = 0; i < 6; i++){
    Serial.print(FileSystemSD.Current_Line[i]);
    }
      Serial.println("prev");
  FileSystemSD.Read_prev_six_char();
  //Print text in current
  for (int i = 0; i < 6; i++){
    Serial.print(FileSystemSD.Current_Line[i]);
    }

}

void loop() {
  // nothing happens after setup finishes.
}

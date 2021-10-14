/*


  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

*/
#include <SPI.h>
#include <SD.h>


//class has to be created before object is being created
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

  //File reading  
  FileSyst FileSystemSD;
  
  Serial.println("now system reading: ");

  //read next six lines
  Serial.println("next");
  FileSystemSD.Read_next_line();
  for (int i = 0; i < 5; i++){
    Serial.print(FileSystemSD.Current_Line[i]);
    }

     //read prev six lines
    Serial.println(" ");
  Serial.println("prev");
  FileSystemSD.Read_prev_line();
  for (int i = 0; i < 5; i++){
    Serial.print(FileSystemSD.Current_Line[i]);
    }


}

void loop() {
  // nothing happens after setup finishes.
}

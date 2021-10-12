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
 class FileSyst {
    private:
      File root = SD.open("/");
    public:
      String Current_File;
      String SDFile1;
      String SDFile2;
      String SDFile3;
      String File_List[3];
      FileSyst() {//constructor
        for (int i = 0; i < 4; i++) {//loop over the 4 first files (we skip file 1) and store the 3 file names
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
        String File_List[] = {SDFile1,SDFile2,SDFile3};
      }

      //TODO create method to toggle Files
      void Toggle_File(){

      }
      //TODO create method to Read file



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

  FileSyst k;
}

void loop() {
  // nothing happens after setup finishes.
}




void FilereadingInit(File dir) {
  unsigned long start;
  unsigned long endtime;

    start = micros();//start timer
    Serial.println("Micro sec per char iteration");
    //while (myFile1.available()) {
    //  myFile1.read();//reads char
    //}
    endtime = micros();//store time
    Serial.println(start);
    Serial.println(endtime);
    }

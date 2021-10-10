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


File root;
File myFile;
char temp;
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

  root = SD.open("/");

  TestFilereading(root);

  Serial.println("done!");
}

void loop() {
  // nothing happens after setup finishes.
}


//READ files:
//Skip file 1 (for whatever reason there is a .dat file that is read) and read the next 3 files unless they are empty;

void TestFilereading(File dir) {
  unsigned long start;
  unsigned long endtime;
  for (int i = 0; i < 4; i++) {//loop over the 4 first files
    Serial.println(i);
    File entry =  dir.openNextFile();
    if (i == 0){
      Serial.println("skipped");
      //skip system file
      }else {
    if (! entry) {
      // no more files
      break;
    }
    start = micros();
    Serial.println(entry.name());
    myFile = SD.open(entry.name());
    Serial.println("Micro sec per char iteration");
    while (myFile.available()) {
      temp = myFile.read();
    }
    endtime = micros();
    Serial.println(start);
    Serial.println(endtime);
      }
    entry.close();
  }
  
}

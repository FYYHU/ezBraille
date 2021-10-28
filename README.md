# Easy-Braille

Easy-Brialle is a 2 part braille display system. Containing the Easy-Braille device and webserver. This README explains the workflow of the repository it is assumed the reader has read the original report.

## Content

- Webserver
- Arduino code



## Webserver

The main back-end code for the site is index.js. It deals with the translation, managing uploaded files and routing. The HTML, CSS and other web assets are stored in the public folder. The hosting of the site is done on Heroku and its address is https://ezbraille.herokuapp.com/.

## Arduino code

At the start of the development of the Arduino the code is into parts for better workflow. 
- Motor.ino: deals with handling character input to motor movement.
- SDFilesV2.ino: Handles the reading of the files in the SD-module.
- TouchSensor.ino: Handles the touch sensor input
- Button.ino: Button input handling

The remaining folders oldcode and test contains old unused code and test codes. The last one MainCode.ino is the final product that contains the assembly and generalisation of the other components into one system.

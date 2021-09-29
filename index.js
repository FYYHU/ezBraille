
//local server setup
//running node index.js will create local server at http://localhost:5000/
//or global server run on https://vast-forest-25811.herokuapp.com/
const express = require('express')
const app = express()
const path = require('path');

var fs = require('fs');
var text = fs.readFileSync("./bigtext.txt", 'utf-8');

app.set('port', (process.env.PORT || 5000))

app.listen(app.get("port"), ()=>{console.log("cool")});

app
  .use(express.static(path.join(__dirname, 'public')))
  .get('/', (req, res) => res.send('/index.html'))






var br = require('braille');

console.log(br.toBraille("b"));
console.log(br.toBraille("B")); //Some limits using this library not capitals


//TODO
//Some byte magic blabla:
//UTF-8 encoding for braille is as follow: its an 2X8 cell and each 1 and 0 represent dot on/off + 2800 offset
//What we need to do is take the hexdec value - 2800 and then to binary we get an 8 bit data of our braille
//https://en.wikipedia.org/wiki/Braille_Patterns for exactly how they mapped it
// either way first 2 bits can be ommited (they rep dot 7 and 8),but since its easier to send bytes then bit we'll just keep it.
//Then its just reading the byte per bit from right to left to know which dot is on.
//for example 01101011 is the same as dots 124
const hex_rot = new Map();




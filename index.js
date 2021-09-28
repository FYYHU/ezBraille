
//local server setup
//running node index.js will create local server at http://localhost:3000/
const express = require('express')
const app = express()
const path = require('path');


app.set('port', (process.env.PORT || 5000))

app.listen(app.get("port"), ()=>{console.log("cool")});

app
  .use(express.static(path.join(__dirname, 'public')))
  .get('/', (req, res) => res.send('/index.html'))




  console.log("tester")



  var fs = require('fs');
  var text = fs.readFileSync("./bigtext.txt", 'utf-8');



var br = require('braille');

console.log(br.toBraille("b"));
console.log(br.toBraille("B")); //Some limits using this library not capitals


//TODO
//Create map that maps our braille output to 2 rotation angles.
//Potential i.e. format "braille" -> 090180 = left rot 90 and right rot 180
//other format is binary i.e. "braille"-> 010111 first 3 digit form left rot, other form right rot = ⠺
const hex_rot = new Map();



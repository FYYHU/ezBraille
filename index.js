
//local server setup
//running node index.js will create local server at http://localhost:3000/
const express = require('express')
const app = express()
const port = 3000
const path = require('path');

app.listen(3000, ()=>{console.log("cool")});

//default load
app.get('/', function(req, res) {
    res.sendFile(path.join(__dirname, 'public/index.html'));
  });


//http://localhost:3000/add will serve this text
app.get('/test', function(req, res) {
    res.send("this is testpage");
  });





  



//below liblouis braille library
  const liblouis = require("liblouis");


  liblouis.enableOnDemandTableLoading("node_modules/liblouis-build/tables"); //path translation tables


//unicode2.dis is experimental dis map
var unicode_braille = liblouis.translateString("tables/unicode.dis,tables/en-us-comp8-ext.utb","k"); // last part is the language and grade table = > en-gb-g1.utb


console.log(unicode_braille);
let decimal = unicode_braille.charCodeAt(0);//gives decimal of unicode
let starter = decimal.toString(16) // converts decimal to hex
console.log(String.fromCharCode(parseInt(starter,16))) // prints unicode char using hexcode
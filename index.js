
//modules
const express = require('express');
const br = require('braille');//braille lib
const fs = require('fs');//file read/write lib
const path = require('path');//path creation lib
const multer = require('multer');//file storage lib
const fsExtra = require('fs-extra');//;delete file lib

const app = express();



//storage upload file setup/location
const storage = multer.diskStorage({
    destination: function(req, file, cb) {
        cb(null, 'uploads/');
    },
  
    // By default, multer removes file extensions so let's add them back
    filename: function(req, file, cb) {
        cb(null, file.fieldname + '-' + Date.now() + path.extname(file.originalname));
    }
  });


//server initialization and default route
app.set('port', (process.env.PORT || 5000))
app.listen(app.get("port"), ()=>{console.log("server running")});
app
  .use(express.static(path.join(__dirname, 'public')))
  .get('/', (req, res) => res.send('/index.html'))



//upload api
app.post('/upload', (req, res) => {
    EmptyUploads();
    let upload = multer({ storage: storage}).single('text');//text is field in html
    
    upload(req, res, function(err) {
        console.log("upload")
        let upload_folder = path.join(__dirname, 'uploads/')
        let first_upload = fs.readdirSync(upload_folder)[0];
        let file_content = fs.readFileSync(path.join(__dirname, 'uploads/' + first_upload), 'utf-8');
        res.send(file_content);
    });
});


function EmptyUploads(){//deletes all files in uploads
  fileDir = path.join(__dirname, 'uploads');
  fsExtra.emptyDirSync(fileDir);
  console.log("accessed");
}



//readfile setup
var text = fs.readFileSync("./bigtext.txt", 'utf-8');





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




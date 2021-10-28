
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
        cb(null, file.originalname +"-" +"translated" + path.extname(file.originalname));
    }
  });


//server initialization and default route
app.set('port', (process.env.PORT || 5000))
app.listen(app.get("port"), ()=>{console.log("server running")});
app
  .use(express.static(path.join(__dirname, 'public')))
  .get('/', (req, res) => res.send('/index.html'))

app.get('/upload', (req,res) => {
  res.sendFile(path.join(__dirname, 'public/Upload-file.html'));
})


//upload api
app.post('/upload', (req, res) => {
    EmptyUploads();
    let upload = multer({ storage: storage}).single('text');//text is field in html
    
    upload(req, res, function(err) {
        console.log("upload")
        Translate();
        res.sendFile(path.join(__dirname, 'public/down.html'));
    });
});

app.get('/Home', (req, res) => {
    res.sendFile(path.join(__dirname, 'public/Home.html'));
});

app.get('/About', (req, res) => {
  res.sendFile(path.join(__dirname, 'public/About.html'));
});

//dowload api 
app.get('/download', function(req, res){
    let upload_folder = path.join(__dirname, 'uploads/')
    let first_upload = fs.readdirSync(upload_folder)[0];
    res.download(path.join(__dirname, 'uploads/' + first_upload)); // Set disposition and send it.
    
  });


//deletes all files in uploads
function EmptyUploads(){
  let fileDir = path.join(__dirname, 'uploads');
  fsExtra.emptyDirSync(fileDir);
  console.log("accessed");
}

//Translate first file in uploads
function Translate(){
    let upload_folder = path.join(__dirname, 'uploads/')
    let first_upload = fs.readdirSync(upload_folder)[0];
    let file_location = path.join(__dirname, 'uploads/' + first_upload);
    var text_file = fs.readFileSync(file_location, 'utf8');
    var translation = br.toBraille(text_file);
    var translation_array = translation.split("");
    for (var i = 0; i < translation_array.length; i++) {
        var offsetted = translation_array[i].charCodeAt(0)-10240+32;
        translation_array[i] = String.fromCharCode(offsetted);
        
      }
    translation = translation_array.join("");
    fs.writeFile(file_location, translation,function(err){
        if (err) throw err;
        console.log("translated");
    })
}









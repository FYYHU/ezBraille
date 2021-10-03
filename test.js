var g = "⠀⠁⠂⠃⠄⠅⠆⠇⠈⠉⠊⠋⠌⠍⠎⠏⠐⠑⠒⠓⠔⠕⠖⠗⠘⠙⠚⠛⠜⠝⠞⠟⠠⠡⠢⠣⠤⠥⠦⠧⠨⠩⠪⠫⠬⠭⠮⠯⠰⠱⠲⠳⠴⠵⠶⠷⠸⠹⠺⠻⠼⠽⠾⠿";
console.log(g);
for (var i = 0; i < g.length; i++) {
    //offset calculation take utf-braille(hex value) = 2800 + hex
    //CharCodeAt returns decimal of char.
    //We remove 2800(hex) = 10240(dec) 
    //we add offset of 20(hex) = 32(dec)
    //Now we get the braille char in ascii format
    //note the empty cell is space with ascii code 32(dec)
    var offsetted = g.charCodeAt(i)-10240+32;
    process.stdout.write(String.fromCharCode(offsetted));
    
  }

  //console.log(String.fromCharCode(32));
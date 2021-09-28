//below liblouis braille library
const liblouis = require("liblouis");


liblouis.enableOnDemandTableLoading("node_modules/liblouis-build/tables"); //path translation tables


let subst = "The Project";


//console.log(liblouis.translateString("tables/unicode.dis,tables/en-us-comp8-ext.utb",subst));


var unicode_braille = liblouis.translateString("tables/unicode.dis,tables/en-gb-g1.utb",subst); // last part is the language and grade table = > en-gb-g1.utb

console.log(unicode_braille);

//let decimal = unicode_braille.charCodeAt(0);//gives decimal of unicode
//let starter = decimal.toString(16) // converts decimal to hex
//tese = String.fromCharCode(parseInt(starter,16)) // prints unicode char using hexcode
//
//const hexbrialle_2rot = new Map();
////TODO map each letter to double digit where first dig rep left and second dig rep right
//console.log(hexbrialle_2rot.get(tese));
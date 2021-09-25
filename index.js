const liblouis = require("liblouis");

liblouis.enableOnDemandTableLoading("node_modules/liblouis-build/tables"); //path translation tables


var unicode_braille = liblouis.translateString("tables/unicode.dis,tables/en-gb-g1.utb", "I finnaly found the table ffs"); // last part is the language and grade table = > en-gb-g1.utb


console.log(unicode_braille);
//console.log(liblouis.backTranslateString("tables/unicode.dis,tables/en-gb-g1.utb", unicode_braille))
// \s matches any whitespace character [\r\n\t\f];
// \S matches any non-white space character

// Q) match the pattern XXxXXxXX
// 'X' is noe-white space and 'x' is white space

var Regex_Pattern = /\S{2}\s\S{2}\s\S{2}/;

function processData(Test_String) {
    //Enter your code here
    
    console.log(!!Test_String.match(Regex_Pattern));
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});

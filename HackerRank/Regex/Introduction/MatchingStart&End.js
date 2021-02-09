// '^' symbol matches the position at the start of a string
// '$' symbol matches the position at the end of string

// Q) Match the pattern Xxxxx.
// 'x' is word Character and 'X' is digit
// Test_string is start with digit and end with '.' symbol
// Test_string's length is 6

var Regex_Pattern = /^\d\w{4}[.]$/;

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

// \w will match any word character => [a-zA-Z0-9];
// \W match any non-word character => [^a-zA-Z0-9];

// Q) match the pattern xxxXxxxxxxxxxxXxxx
// 'x' is any word character and 'X' is any non-word character

var Regex_Pattern = /\w{3}\W\w{10}\W\w{3}/; 

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

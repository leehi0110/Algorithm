// The character class [ ] matches only one out of several characters placed inside the square brackets.

// Q) S.length = 6
// First character: 1 or 2 or 3
// Second character: 1 or 2 or 0
// Third character: x or s or 0
// Fourth character: 3 or 0 or A or a
// Fifth character: x or s or u
// Sixth character: . or ,

var Regex_Pattern = /^[123][120][sx0][30Aa][xsu][.,]$/;

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

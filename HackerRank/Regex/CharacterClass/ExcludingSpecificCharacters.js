// The negated character class [^] matches any character that is not in the square brackets.

var Regex_Pattern = /^[^\d][^aeiou][^bcDF][\S][^AEIOU][^.,]$/;

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
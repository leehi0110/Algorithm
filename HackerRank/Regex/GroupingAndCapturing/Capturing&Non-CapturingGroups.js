var Regex_Pattern = /(ok){3,}/;

function processData(Test_String) {
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

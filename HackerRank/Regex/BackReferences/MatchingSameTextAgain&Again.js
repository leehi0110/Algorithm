var Regex_Pattern = /^([a-z])([\w])([\s])([^\w])(\d)([^\d])([A-Z])([a-zA-Z])([aeiouAEIOU])([^\s])\1\2\3\4\5\6\7\8\9\10$/;

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

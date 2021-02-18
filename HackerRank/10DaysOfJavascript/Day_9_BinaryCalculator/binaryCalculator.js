const res = document.querySelector("#res");
const btn0 = document.querySelector("#btn0");
const btn1 = document.querySelector("#btn1");
const btnClr = document.querySelector("#btnClr");
const btnEql = document.querySelector("#btnEql");
const btnSum = document.querySelector("#btnSum");
const btnSub = document.querySelector("#btnSub");
const btnMul = document.querySelector("#btnMul");
const btnDiv = document.querySelector("#btnDiv");

let resText = "";
let firstBinary = "";
let secondBinary = "";
let operator = "";

btn0.addEventListener("click", clickNumber);
btn1.addEventListener("click", clickNumber);
btnClr.addEventListener("click", clickClear);
btnEql.addEventListener("click", getResult);
btnSum.addEventListener("click", clickOper);
btnSub.addEventListener("click", clickOper);
btnMul.addEventListener("click", clickOper);
btnDiv.addEventListener("click", clickOper);

function clickNumber(e) {
  let number = e.target.innerText;

  if (operator === "") {
    firstBinary += number.toString();
  } else {
    secondBinary += number.toString();
  }

  resText += number.toString();
  res.innerText = resText;
}

function clickClear() {
  firstBinary = "";
  secondBinary = "";
  operator = "";
  resText = "";
  res.innerText = resText;
}

function clickOper(e) {
  let selectOper = e.target.innerText;
  operator = selectOper;
  resText += selectOper;
  res.innerText = resText;
}

function getResult() {
  let firstDec = parseInt(firstBinary, 2);
  let secondDec = parseInt(secondBinary, 2);
  let result;

  switch (operator) {
    case "+":
      result = firstDec + secondDec;
      break;
    case "-":
      result = firstDec - secondDec;
      break;
    case "*":
      result = firstDec * secondDec;
      break;
    default:
      result = parseInt(firstDec / secondDec);
  }
  resText = result.toString(2);
  res.innerText = resText;
}

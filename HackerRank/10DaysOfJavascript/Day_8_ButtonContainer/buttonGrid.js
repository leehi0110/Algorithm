const middleBtn = document.querySelector("#btn5");
const btn1 = document.querySelector("#btn1");
const btn2 = document.querySelector("#btn2");
const btn3 = document.querySelector("#btn3");
const btn4 = document.querySelector("#btn4");
const btn6 = document.querySelector("#btn6");
const btn7 = document.querySelector("#btn7");
const btn8 = document.querySelector("#btn8");
const btn9 = document.querySelector("#btn9");

middleBtn.addEventListener("click", () => {
  let varNum = btn1.innerText;
  btn1.innerText = btn4.innerText;
  btn4.innerText = btn7.innerText;
  btn7.innerText = btn8.innerText;
  btn8.innerText = btn9.innerText;
  btn9.innerText = btn6.innerText;
  btn6.innerText = btn3.innerText;
  btn3.innerText = btn2.innerText;
  btn2.innerText = varNum;
});

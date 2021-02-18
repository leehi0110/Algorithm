const countBtn = document.querySelector("#btn");

countBtn.addEventListener("click", (e) => {
  let nowCnt = parseInt(e.target.innerText);
  countBtn.innerText = (nowCnt + 1).toString();
});

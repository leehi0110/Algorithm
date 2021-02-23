function solution(begin, target, words) {
  // 시작 문자 -> 거쳐가는 문자 -> 타겟 문자 -> 문자 목록

  let min = Infinity;

  for (let i = 0; i < words.length; i++) {
    let word = words[i];
    let tempWords = words.slice();
    tempWords.splice(i, 1);

    let minCnt = changeAvailable(begin, word, target, tempWords);
    if (min > minCnt) min = minCnt;
  }

  return min === Infinity ? 0 : min;
}

function changeAvailable(now, next, target, words) {
  let checkResult = isSimilar(now, next);
  let min = Infinity;

  if (isSimilar(now, target) === "same") return 0;

  if (checkResult === "diff") return Infinity;
  else {
    for (let i = 0; i < words.length; i++) {
      let word = words[i];
      let tempWords = words.slice();

      tempWords.splice(i, 1);
      let minCnt = 1 + changeAvailable(next, word, target, tempWords);
      if (min > minCnt) min = minCnt;
    }
  }

  return min;
}

function isSimilar(a, b) {
  let similarCnt = 0;

  for (let i = 0; i < a.length; i++) {
    if (a[i] === b[i]) similarCnt++;
  }

  if (a.length === similarCnt) return "same";
  else if (a.length - 1 === similarCnt) return "similar";
  else return "diff";
}

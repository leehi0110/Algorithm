// 풀이 시간 30 => 22:00 - 22:30

const inputString = "02984";
// const inputString = "567";

//-----------------------------[input]

let splitString = inputString.split('');
let result = parseInt(splitString[0]);

for(let i=1;i<splitString.length;i++) {
  let parseNum = parseInt(splitString[i]);

  // if(parseNum === 0 || parseNum === 1 || result === 0 || result === 1) {
  //   result += parseNum;
  // } else result *= parseNum;

  // 답지에 제시된 더 간단한 알고리즘
  if(result < 2 || parseNum < 2) {
    result += parseNum;
  } else result *= parseNum;
  
}

console.log(result);
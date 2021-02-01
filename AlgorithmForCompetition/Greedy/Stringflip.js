// 풀이 시간 20 => 22:17 - 22:37

// const inputString = "0001100";
// const inputString = "10110010";
const inputString = "1100101100001";

//-----------------------------[input]

let flag, zeroCnt = 0, oneCnt = 0;

if(inputString[0] === '0') {
  flag = 0;
  zeroCnt++;
} else {
  flag = 1;
  oneCnt++;
}

for(let i=1;i<inputString.length;i++) {
  let parseNum = parseInt(inputString[i]);

  if(parseNum === flag) continue;
  else {
    if(flag === 0) {
      oneCnt ++;
      flag = 1;
    } else {
      zeroCnt ++;
      flag = 0;
    }
  }
}

zeroCnt > oneCnt ? console.log(oneCnt) : console.log(zeroCnt);
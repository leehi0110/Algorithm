// 풀이 시간 30 => 15:10  - 15:40

const N = 5;
const coin = [3,2,1,1,9];

//-----------------------------[input]

coin.sort((a,b) => a-b);
let target = 1;

for(let c of coin) {
  if(c <= target) {
    target += c;
  } else break;
}

console.log(target);
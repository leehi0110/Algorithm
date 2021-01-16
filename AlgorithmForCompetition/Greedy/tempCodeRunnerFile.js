const N = 5; // 배열의 크기
const M = 8; // 숫자가 더해지는 횟수
const K = 3; // 연속으로 더해질 수 있는 횟수

let inputArray = [2,4,5,4,6];

//---------------------------------------- [ input ]

let sum = 0;
let k_cnt = 0;
let isMax = true;
inputArray.sort((a,b) => b-a);

for(let i=0;i<M;i++) {

  if(k_cnt === K) {
    isMax = !isMax;
    k_cnt = 0;
  }
  
  isMax ? sum += inputArray[0] : sum += inputArray[1];
  console.log(sum);
  k_cnt++;
}

console.log(sum);
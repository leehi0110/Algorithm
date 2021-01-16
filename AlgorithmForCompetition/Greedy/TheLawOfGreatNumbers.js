const N = 5; // 배열의 크기
const M = 8; // 숫자가 더해지는 횟수
const K = 3; // 연속으로 더해질 수 있는 횟수

let inputArray = [2,4,5,4,6];

//---------------------------------------- [ input ]

let sum = 0;
let maxCnt = (Math.floor(M/K) * K);

inputArray.sort((a,b) => b-a);

sum += (inputArray[0] * maxCnt + inputArray[1] * (M-maxCnt));

console.log(sum);
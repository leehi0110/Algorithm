// 풀이 시간 30 => 13:30 - 14:00

// const N = 5;
// const M = 3;
// const weight = [1,3,2,3,2];

const N = 8;
const M = 5;
const weight = [1,5,4,3,2,4,5,2];

//-----------------------------[input]

// let cnt = 0;

// for(let i=0;i<weight.length;i++) {
//   for(let j=i+1;j<weight.length;j++) {
//     if(weight[i] !== weight[j]) cnt++;
//   }
// }

// console.log(cnt);

//----------------------------- [시간 복잡도를 줄인 책 풀이]

const weigthCnt = Array.from({length: 11}, () => 0);
let cnt = 0;

for(let i=0;i<weight.length;i++) {
  weigthCnt[weight[i]]++;
}

for(let i=1;i<weigthCnt.length;i++) {
  const left = N - weigthCnt[i];
  cnt += weigthCnt[i] * left;
}

console.log(cnt/2);
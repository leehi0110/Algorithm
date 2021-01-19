// 풀이 시간 20 => 22:45 - 23:05

const N = 5;
const K = 3;
const arrA = [1,2,5,4,3];
const arrB = [5,5,6,6,5];

//-----------------------------[input]

let sortA = arrA.sort((a,b) => a-b);
let sortB = arrB.sort((a,b) => b-a);

for(let i=0;i<K;i++) {
  [sortA[i], sortB[i]] = [sortB[i], sortA[i]];
}

const reducer = (accumulate, currentVal) => accumulate + currentVal;
console.log(sortA.reduce(reducer,0));

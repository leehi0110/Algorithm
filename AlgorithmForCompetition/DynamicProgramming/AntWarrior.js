// 풀이 시간 30 => 10:38 - 11:08

const N = 4;
const arr = [1,3,1,5];

//-----------------------------[input]

let d = Array.from({length: 101}, () => 0);

d[0] = arr[0];
d[1] = arr[1];

for(let i=2;i<N;i++) {
  d[i] = Math.max(d[i-1],d[i-2] + arr[i]);
}

console.log(d[N-1]);

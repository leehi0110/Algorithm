// 풀이 시간 20 => 11:16 - 11:36

const N = 3;

//-----------------------------[input]

let d = Array.from({length: 1001}, () => 0);

d[1] = 1;
d[2] = 3;

for(let i=3;i<N+1;i++) {
  d[i] = (d[i-1] + (d[i-2] * 2))%796796;
}

console.log(d[N]);
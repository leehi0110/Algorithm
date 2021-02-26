// 풀이 시간 30 => 19:40 - 20:10

// const N = 3;
// const M = 4;
// const arr = [
//   [1, 3, 3, 2],
//   [2, 1, 4, 1],
//   [0, 6, 4, 7],
// ];

const N = 4;
const M = 4;
const arr = [
  [1, 3, 1, 5],
  [2, 2, 4, 1],
  [5, 0, 2, 3],
  [0, 6, 1, 2],
];

//-----------------------------[input]

let d = Array.from(Array(N), () => Array(M).fill(0));

d[0][0] = arr[0][0];
d[1][0] = arr[1][0];
d[2][0] = arr[2][0];

for (let i = 1; i < M; i++) {
  for (let j = 0; j < N; j++) {
    if (j === 0) {
      d[j][i] = arr[j][i] + Math.max(d[j][i - 1], d[j + 1][i - 1]);
    } else if (j === N - 1) {
      d[j][i] = arr[j][i] + Math.max(d[j][i - 1], d[j - 1][i - 1]);
    } else {
      d[j][i] =
        arr[j][i] + Math.max(d[j - 1][i - 1], d[j][i - 1], d[j + 1][i - 1]);
    }
  }
}

let max = 0;

for (let i = 0; i < N; i++) {
  if (max < d[i][M - 1]) max = d[i][M - 1];
}

console.log(max);

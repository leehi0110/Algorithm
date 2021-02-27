// Case 1:
// const N = 5;
// const M = 7;
// const X = 4;
// const K = 5;
// const Start = 1;

// ==================

//Case 2:
const N = 4;
const M = 2;
const X = 3;
const K = 4;
const Start = 1;

const graph = Array.from({ length: N }, () => Array(N).fill(Infinity));

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    if (i === j) graph[i][j] = 0;
  }
}

// Case 1:
// graph[0][1] = 1;
// graph[1][0] = 1;
// graph[0][2] = 1;
// graph[2][0] = 1;
// graph[0][3] = 1;
// graph[3][0] = 1;
// graph[1][3] = 1;
// graph[3][1] = 1;
// graph[2][3] = 1;
// graph[3][2] = 1;
// graph[2][4] = 1;
// graph[4][2] = 1;
// graph[3][4] = 1;
// graph[4][3] = 1;
// ====================
// Case 2:
graph[0][2] = 1;
graph[2][0] = 1;
graph[1][3] = 1;
graph[3][1] = 1;

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    for (let k = 0; k < N; k++) {
      graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
    }
  }
}

let result = graph[Start - 1][K - 1] + graph[K - 1][X - 1];

if (result === Infinity) console.log(-1);
else console.log(result);

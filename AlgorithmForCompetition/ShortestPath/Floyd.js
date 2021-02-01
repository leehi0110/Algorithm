// 풀이 시간 40 => 20:40 - 21:20

const N = 5;
const M = 14;

const graph = Array.from(new Array(N), () => Array(N).fill(Infinity));

for(let i=0;i<N;i++) {
  for(let j=0;j<N;j++) {
    if(i === j) graph[i][j] = 0;
  }
}

graph[0][1] = 2;
graph[0][2] = 3;
graph[0][3] = 1;
graph[0][4] = 10;
graph[1][3] = 2;
graph[2][3] = 1;
graph[2][4] = 1;
graph[3][4] = 3;
// graph[2][4] = 10;
graph[2][0] = 8;
// graph[0][3] = 2;
graph[4][0] = 7;
// graph[2][3] = 2;
graph[4][1] = 4;


//-----------------------------[input]

for(let k=0;k<N;k++) {
  for(let i=0;i<N;i++) {
    for(let j=0;j<N;j++) {
      graph[i][j] = Math.min(graph[i][j],graph[i][k] + graph[k][j]);
    }
  }
}

for(let i=0;i<N;i++) {
  for(let j=0;j<N;j++) {
    if(graph[i][j] === Infinity) graph[i][j] = 0;
  }
}

console.log(graph);
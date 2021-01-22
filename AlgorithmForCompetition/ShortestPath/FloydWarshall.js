const INF = Infinity;

const N = 4;
const M = 7;

const graph = Array.from(new Array(N), () => Array(N).fill(INF));

for(let i=0;i<N;i++) {
  for(let j=0;j<N;j++) {
    if(i === j) graph[i][j] = 0;
  }
}

graph[0][1] = 4;
graph[0][3] = 6;
graph[1][0] = 3;
graph[1][2] = 7;
graph[2][0] = 5;
graph[2][3] = 4;
graph[3][2] = 2;

//-----------------------------[input]

console.log(graph);
console.log('-------');

for(i=0;i<N;i++) {
  for(j=0;j<N;j++){
    for(let k=0;k<N;k++) {
      graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
    }
  }
}

for(i=0;i<N;i++) {
  console.log(graph[i]);
}


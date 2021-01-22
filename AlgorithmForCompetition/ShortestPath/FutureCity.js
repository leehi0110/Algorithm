// 풀이 시간 40 => 12:15 - 12:55

const INF = Infinity;

// const N = 5; // node
// const X = 4; // second visit
// const K = 5; // first visit

const N = 4;
const X = 3;
const K = 4;

const graph = Array.from(Array(N), () => Array(N).fill(INF));

for(let i=0;i<N;i++) {
  for(let j=0;j<N;j++) {
    if(i === j) graph[i][j] = 0;
  }
}

graph[0][2] = 3;
graph[1][3] = 4;

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

//-----------------------------[input]

for(i=0;i<N;i++) {
  for(j=0;j<N;j++) {
    for(let k=0;k<N;k++) {
      graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
      graph[j][i] = graph[i][j];
    }
  }
}

const short = graph[0][K-1] + graph[K-1][X-1];
if(short !== INF) console.log(short);
else console.log(-1);


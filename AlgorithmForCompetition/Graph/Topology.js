const indegree = [0,1,1,2,1,2,1];
const graph = [[1,4],[2,5],[3],[6],[5],[3],[]];
const que = [];
const result = [];

//-----------------------------[input]

que.push(0);

while(que.length > 0) {
  const now = que.shift();
  result.push(now);

  for(let i=0;i<graph[now].length;i++) {
    let degree = graph[now][i];

    indegree[degree] --;
    if(indegree[degree] === 0) {
      que.push(degree);
    }
  }
}

console.log(result);

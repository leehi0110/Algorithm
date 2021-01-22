INF = Infinity;

const N = 6;
const M = 11;
const start = 1;

let graph = Array.from({length: N+1}, () => []);
let visited = Array.from({length: N+1}, () => false);
let distance = Array.from({length: N+1}, () => INF);

graph[1].push([2,2]);
graph[1].push([3,5]);
graph[1].push([4,1]);
graph[2].push([3,3]);
graph[2].push([4,2]);
graph[3].push([2,3]);
graph[3].push([6,5]);
graph[4].push([3,3]);
graph[4].push([5,1]);
graph[5].push([3,1]);
graph[5].push([6,2]);

//-----------------------------[input]

dijkstra(start);

for(let i=1;i<N+1;i++){
  if(distance[i] === INF) {
    console.log("Infinity");
  } else {
    console.log(distance[i]);
  }
}

function dijkstra(start) {
  distance[start] = 0;
  visited[start] = true;

  for(let end of graph[start]) {
    distance[end[0]] = end[1];
  }

  for(let i=0;i<N-1;i++) {

    let now = get_smallest_node();
    visited[now] = true;

    for(let end of graph[now]) {
      let cost = distance[now] + end[1];
      if(cost < distance[end[0]]) {
        distance[end[0]] = cost;
      }
    }
  }
}

function get_smallest_node() {
  min_val = INF;
  index = 0;
  for(let i=1;i<N+1;i++) {
    if(distance[i] < min_val && visited[i] === false){
      min_val = distance[i];
      index = i;
    }
  }
  return index;
}


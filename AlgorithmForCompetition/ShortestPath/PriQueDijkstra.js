INF = Infinity;

class priorityQueue {
  constructor() {
    this.que = [];
  };

  enque(nodeIndex, dist) {
    this.que.push([nodeIndex,dist]);
  };

  deque () {
    this.que.sort((a,b) => {
      return a[1] - b[1];
    });

    return this.que.splice(0,1);
  }
}

const N = 6;
const M = 11;

let graph = Array.from({length: N+1}, () => []);
let visited = Array.from({length: N+1}, () => false);
let distance = Array.from({length: N+1}, () => INF);
let pq = new priorityQueue();
pq.enque(1,0);
distance[1] = 0;

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

while(pq.que.length > 0) {
  const [[nowNode, nowDis]] = pq.deque();
  if(visited[nowNode]) continue;
  
  visited[nowNode] = true;

  for(let [next, dis] of graph[nowNode]) {
    if(distance[next] >  distance[nowNode] + dis) {
      distance[next] = distance[nowNode] + dis;
      pq.enque(next, distance[next]);
    }
  }
}

for(let i=1;i<N+1;i++) {
  if(distance[i] === INF) console.log('infi');
  else console.log(distance[i]);
}


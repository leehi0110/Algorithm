// 풀이 시간 60 => 12:33 - 13:33

class priorityQueue {
  constructor() {
    this.que = [];
  }

  enque (nodeIndex, time) {
    this.que.push([nodeIndex,time]);
  }

  deque () {
    this.que.sort((a,b) => a[1] - b[1]);

    return this.que.splice(0,1);
  }
}

const INF = Infinity;
const N = 3; // 도시의 개수
const M = 2; // 통로의 개수
const C = 1; // 메세지를 보내고자 하는 도시

//-----------------------------[input]

const pq = new priorityQueue();

const graph = Array.from({length: N}, () => []);
const visited = Array(N).fill(false);
const time = Array.from({length: N}, () => INF);

graph[0].push([1,4]);
graph[0].push([2,2]);

pq.enque(0,0);
time[0] = 0;

while(pq.que.length > 0) {
  const [[nodeIndex, times]] = pq.deque();

  if(visited[nodeIndex]) continue;
  
  visited[nodeIndex] = true;

  for(let [targetNode, targetTime] of graph[nodeIndex]) {
      if(time[targetNode] > time[nodeIndex] + targetTime) {
        time[targetNode] = time[nodeIndex] + targetTime;
        pq.enque(targetNode, time[targetNode]);
      }
  }
}

const arrived = visited.filter(item => item === true);

const maxTime = time.filter(item => item !== INF);

console.log(arrived.length-1, Math.max(...maxTime));


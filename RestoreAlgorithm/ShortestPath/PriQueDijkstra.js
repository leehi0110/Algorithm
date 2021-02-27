const N = 6;
const M = 11;
const Start = 1;

class PriorityQueue {
  constructor() {
    this.que = [];
  }

  enque(node, distance) {
    this.que.push([node, distance]);
  }

  deque() {
    this.que.sort((a, b) => a[1] - b[1]);
    return this.que.splice(0, 1);
  }
}

const distance = Array.from({ length: N + 1 }, () => Infinity);
const graph = Array.from(Array(N + 1), () => []);
const pq = new PriorityQueue();

graph[1].push([2, 2]);
graph[1].push([3, 5]);
graph[1].push([4, 1]);
graph[2].push([3, 3]);
graph[2].push([4, 2]);
graph[3].push([2, 3]);
graph[3].push([6, 5]);
graph[4].push([3, 3]);
graph[4].push([5, 1]);
graph[5].push([3, 1]);
graph[5].push([6, 2]);

distance[Start] = 0;
pq.enque(1, 0);

while (pq.que.length > 0) {
  const [[node, dist]] = pq.deque();

  if (distance[node] < dist) continue;

  for (let [next, nextDis] of graph[node]) {
    if (distance[next] > distance[node] + nextDis) {
      distance[next] = distance[node] + nextDis;
      pq.enque(next, distance[next]);
    }
  }
}

for (let d of distance) {
  if (d !== Infinity) console.log(d);
}

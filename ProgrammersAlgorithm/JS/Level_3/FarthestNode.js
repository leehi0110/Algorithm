function solution(n, edge) {
  var answer = 0;
  const graph = Array.from({ length: n + 1 }, () => []);
  const distance = Array.from({ length: n + 1 }, () => Infinity);
  const visited = Array.from({ length: n + 1 }, () => false);

  edge.sort((a, b) => {
    if (a[0] === b[0]) return a[1] - b[1];
    else return a[0] - b[0];
  });

  for (var i = 0; i < edge.length; i++) {
    let [a, b] = edge[i];
    graph[a].push(b);
    graph[b].push(a);
  }

  visited[1] = true;
  distance[1] = 0;

  for (let next of graph[1]) {
    distance[next] = 1;
  }

  for (var i = 0; i < n - 1; i++) {
    var minIdx = getSmall(visited, distance);
    visited[minIdx] = true;

    for (let end of graph[minIdx]) {
      let cost = distance[minIdx] + 1;
      if (cost < distance[end]) {
        distance[end] = cost;
      }
    }
  }
  var maxDis = 0;

  for (var i = 1; i < distance.length; i++) {
    if (distance[i] > maxDis) {
      maxDis = distance[i];
      answer = 1;
    } else if (distance[i] == maxDis) {
      answer++;
    }
  }

  return answer;
}

function getSmall(visited, distance) {
  var minIdx = Infinity;
  var minVal = Infinity;

  for (var i = 1; i < distance.length; i++) {
    if (!visited[i] && distance[i] < minVal) {
      minVal = distance[i];
      minIdx = i;
    }
  }
  return minIdx;
}

answer = solution(6, [
  [3, 6],
  [4, 3],
  [3, 2],
  [1, 3],
  [1, 2],
  [2, 4],
  [5, 2],
]);

console.log(answer);

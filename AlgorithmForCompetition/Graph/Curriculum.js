// 풀이 시간 50 => 10:35 - 11:25

const N = 5;

const lectures = [
  [10], [10, 0], [4,0], [4,2,0], [3,2]
];

//-----------------------------[input]

let indegree = Array.from({length: N}, () => 0);
let graph = Array.from({length: N}, () => []);
let time = Array.from({length: N}, () => [0]);
let que = [];

for(let i=0;i<lectures.length;i++) {
  time[i][0] = lectures[i][0];

  for(let j=1;j<lectures[i].length;j++) {
    indegree[i]++;
    graph[lectures[i][j]].push(i);
  }
}

console.log(time);

for(i=0;i<indegree.length;i++) {
  if(indegree[i] === 0) que.push(i);
}

while(que.length > 0) {
  const now = que.shift();

  const basicTime = time[now][0];
  if(time[now].length === 0) console.log(basicTime);
  else {
    time[now].splice(0,1);
    const maxTime = Math.max(...time[now]);
    console.log(basicTime + maxTime);
  }

  for(j=0;j<graph[now].length;j++) {
    const index = graph[now][j];

    indegree[index]--;
    if(indegree[index] === 0) que.push(index);
    time[index].push(basicTime);
    // time[index].push(time[index][0] + time[now][0]);
  }
}



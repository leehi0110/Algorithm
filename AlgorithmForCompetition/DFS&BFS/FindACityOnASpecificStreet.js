// 풀이 시간 30 => 13:08 - 13:48

const N = 4;
const M = 4;
const K = 2;
const X = 1;
const street = [[],[2,3],[3,4],[],[]];

// const N = 4;
// const M = 3;
// const K = 2;
// const X = 1;
// const street = [[],[2,3,4],[],[],[]];

// const N = 4;
// const M = 4;
// const K = 1;
// const X = 1;
// const street = [[],[2,3],[3,4],[],[]];

const distance = Array.from({length: N+1}, () => Infinity);

//-----------------------------[input]

let queue = [];

for(let i of street[X]) {
  queue.push(i);
  distance[i] = 1;
}

while(queue.length > 0) {
  const now = queue[0];
  queue.shift();

  for(let i of street[now]) {
    queue.push(i);
    if(distance[i] > 1 + distance[now]) distance[i] = 1 + distance[now];
  }
}

let temp = [];

for(let i=0;i<distance.length;i++) {
  if(distance[i] === K) temp.push(i);
}

if(temp.length === 0) console.log(-1);
else temp.forEach(e => console.log(e));
// 풀이 시간 40 => 10:05 - 10:45

const N = 7;
const M = 12;

const arr = [
  [1,2,3], [1,3,2], [3,2,1], [2,5,2], [3,4,4], [7,3,6],
  [5,1,5], [1,6,2], [6,4,1], [6,5,3], [4,5,3], [6,7,4]
];

//-----------------------------[input]

const way = Array.from({length: N+1}, () => []);
let root = [];

for(let i=0;i<N+1;i++) {
  root.push(i);
}

let totalCost = 0;
let max_cost = -Infinity;

for(let [start, end, cost] of arr) {
  way[start].push(end);
  way[end].push(start);
}

arr.sort((a,b) => a[2] - b[2]);

for(let [start, end, cost] of arr) {

  const startParent = findParent(root,start);
  const endParent = findParent(root,end);

  if(startParent === endParent) continue;
  else {
    if(startParent > endParent) {
      root[startParent] = endParent;
    } else {
      root[endParent] = startParent;
    }

    if(max_cost < cost) max_cost = cost;

    totalCost += cost;
  }
}

console.log(totalCost);
console.log(totalCost - max_cost);

function findParent(root, a) {
  if(root[a] !== a) {
    root[a] = findParent(root,root[a]);
  }

  return root[a];
}








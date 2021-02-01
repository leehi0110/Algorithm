// 풀이 시간 40 => 21:25 - 22:05

const N = 5;
const M = 4;

const arr = [
  [0,1,0,1,1],
  [1,0,1,1,0],
  [0,1,0,0,0],
  [1,1,0,0,0],
  [1,0,0,0,0]
];

const travel = [2,3,4,3]
//-----------------------------[input]

let parent = Array.from({length: N}, () => 0);

for(let i=0;i<N;i++) {
  parent[i] = i;
}

for(let i=0;i<N;i++) {
  for(let j=0;j<N;j++) {
    if(arr[i][j] === 1) {
      if(findParent(parent,i) === findParent(parent,j)) continue;
      else {
        unionParent(parent,i,j);
      }
    }
  }
}

for(let i=0;i<travel.length-1;i++) {
  if(findParent(parent,travel[i]-1) !== findParent(parent,travel[i+1]-1)) {
    console.log("NO");
    break;
  }

  if(i === travel.length-2) console.log("YES");
}

function findParent(parent, node) {
  if(parent[node] !== node) {
    parent[node] = findParent(parent,parent[node]);
  }

  return parent[node];
}

function unionParent(parent,i,j) {
  const parentI = findParent(parent,i);
  const parentJ = findParent(parent,j);

  if(parentI < parentJ) {
    parent[j] = parentI;
  } else parent[j] = parentJ;
}

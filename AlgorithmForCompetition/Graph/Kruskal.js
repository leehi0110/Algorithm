const arr = [[1,2,29],[1,5,75],[2,3,35],[2,6,34],[3,4,7],[4,6,23],[4,7,13],[5,6,53],[6,7,25]];
const parent = [0,1,2,3,4,5,6,7];

//-----------------------------[input]

arr.sort((a,b) => a[2] - b[2]);
let minCost = 0;

for(let [first, second, cost] of arr) {
  if(findParent(parent,first) === findParent(parent,second)) continue;
  else {
    unionParent(parent,first,second);
    minCost += cost;
  }
}

console.log(minCost);

function unionParent(parent, a, b) {
  const parentA = findParent(parent,a);
  const parentB = findParent(parent,b);

  if(parentA < parentB) {
    parent[parentB] = parentA;
  } else parent[parentA] = parentB;

}

function findParent(parent, target) {
  if(parent[target] !== target) {
    parent[target] = findParent(parent,parent[target]);
  }
  return parent[target];
}


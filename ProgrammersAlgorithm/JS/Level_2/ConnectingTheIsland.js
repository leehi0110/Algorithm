function solution(n, costs) {
  var answer = 0;
  let parent = Array.from({length: n+1},() => 0);
  
  for(let i=0;i<n+1;i++) {
      parent[i] = i;
  }
  
  costs.sort((a,b) => a[2] - b[2]);
  
  for(let i=0;i<costs.length;i++) {
      const [start, end, price] = costs[i];
      if(findParent(parent,start) !== findParent(parent,end)) {
          unionParent(parent, start, end);
          answer += price;
      }
  }
  
  return answer;
}

function findParent(parent, x) {
  if(parent[x] !== x) {
      parent[x] = findParent(parent,parent[x]);
  }
  return parent[x];
}

function unionParent(parent, x, y) {
  const parentX = findParent(parent,x);
  const parentY = findParent(parent,y);
  
  if(parentX < parentY) {
      parent[parentY] = parentX;
  } else parent[parentX] = parentY;
}
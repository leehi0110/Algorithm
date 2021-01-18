const N = 4;
const M = 4;
let place = [1,1];
let direction = 0;
let map = [[1,1,1,1],[1,0,0,1],[1,1,0,1],[1,1,1,1]];

//-----------------------------[input]

const move = [[0,-1],[-1,0],[0,1],[1,0]];
let original = direction;
let cnt = 1;

while(1) {
  direction = (direction+1)%4;
  let afterX = place[0] + move[direction][0];
  let afterY = place[1] + move[direction][1];
  
  if(afterX >= 0 && afterX < N && afterY >= 0 && afterY < M) {
    if(map[afterX][afterY] === 0) {
      map[place[0],place[1]] = 2; // 방문
      place[0] = afterX;
      place[1] = afterY;
      original = direction;
      cnt++;
    }
  }

  if(direction === original) {
    if(map[afterX][afterY] !== 1) {
      place[0] = afterX;
      place[1] = afterY;
    }
    else break;
  }
}

console.log(cnt);
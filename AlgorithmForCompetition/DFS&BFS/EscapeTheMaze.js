// 풀이시간 30 => 53 ~ 23

// case: 1
// const N = 5;
// const M = 6;
// const maze = [
//   [1,0,1,0,1,0],
//   [1,1,1,1,1,1],
//   [0,0,0,0,0,1],
//   [1,1,1,1,1,1],
//   [1,1,1,1,1,1]
// ];

// case: 2
const N = 3;
const M = 3;
const maze = [
  [1,1,0],
  [0,1,0],
  [0,1,1]
];

//-----------------------------[input]

const INFI = 99999999;
let nowX = 0;
let nowY = 0;

console.log(recure(nowX,nowY, maze));

function recure(nowX, nowY, maze) {

  if(nowX === N-1 && nowY === M-1) return 1;
  else if(nowX === N-1 && nowY < M) return 1 + recure(nowX,nowY+1);
  else if(nowX < N && nowY === M-1) return 1 + recure(nowX+1,nowY);
  else {
    if(maze[nowX][nowY] === 0) return INFI;
    else {
      const right = 1 + recure(nowX+1,nowY,maze);
      const down = 1 + recure(nowX,nowY+1,maze);

      return right > down ? down : right;
    }
  }
}
// const N = 5;
// const M = 6;

// const maze = [
//   [1, 0, 1, 0, 1, 0],
//   [1, 1, 1, 1, 1, 1],
//   [0, 0, 0, 0, 0, 1],
//   [1, 1, 1, 1, 1, 1],
//   [1, 1, 1, 1, 1, 1],
// ];

const N = 3;
const M = 3;

const maze = [
  [1, 1, 0],
  [0, 1, 0],
  [0, 1, 1],
];

const escape = (maze, x, y) => {
  let right, down;

  if (x === N - 1 && y === M - 1) {
    return 1;
  } // 도착한 경우
  else {
    if (x < N && y < M) {
      if (maze[x][y] === 0) return Infinity;
      else {
        right = 1 + escape(maze, x + 1, y);
        left = 1 + escape(maze, x, y + 1);
      }
    } else return Infinity;
  } // 도착하지 않은 경우

  if (right > left) return left;
  else return right;
};

console.log(escape(maze, 0, 0));

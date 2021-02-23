// 풀이 시간 50 => 14:25 - 15:15

const N = 3; // virusMap size
const K = 3; // Max virus number
const virusMap = [
  [1, 0, 2],
  [0, 0, 0],
  [3, 0, 0],
]; // virusMap
const S = 2; // Sec
const X = 3; // x좌표
const Y = 2; // y좌표

// const N = 3;
// const K = 3;
// const virusMap = [
//   [1, 0, 2],
//   [0, 0, 0],
//   [3, 0, 0],
// ];
// const S = 1;
// const X = 2;
// const Y = 2;

//-----------------------------[input]

let que = [[], [], [], []];

for (let i = 0; i < S; i++) {
  for (let j = 0; j < N; j++) {
    for (let k = 0; k < N; k++) {
      que[virusMap[j][k]].push([j, k]);
    }
  }

  for (let j = 1; j < que.length; j++) {
    let virusSize = que[j].length;
    for (let k = 0; k < virusSize; k++) {
      let [x, y] = que[j].shift();

      if (x - 1 >= 0 && virusMap[x - 1][y] === 0) {
        virusMap[x - 1][y] = j;
      }
      if (x + 1 < N && virusMap[x + 1][y] === 0) {
        virusMap[x + 1][y] = j;
      }
      if (y - 1 >= 0 && virusMap[x][y - 1] === 0) {
        virusMap[x][y - 1] = j;
      }
      if (y + 1 < N && virusMap[x][y + 1] === 0) {
        virusMap[x][y + 1] = j;
      }
    }
  }
}

console.log(virusMap[X - 1][Y - 1]);

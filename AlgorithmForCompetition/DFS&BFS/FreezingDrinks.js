// 제한시간 30 => 10~40

// const frame = [[0,0,1,1,0],[0,0,0,1,1],[1,1,1,1,1],[0,0,0,0,0]];
// const frame = [
//   [0,0,0,0,0,1,1,1,1,0,0,0,0,0],
//   [1,1,1,1,1,1,0,1,1,1,1,1,1,0],
//   [1,1,0,1,1,1,0,1,1,0,1,1,1,0],
//   [1,1,0,1,1,1,0,1,1,0,0,0,0,0],
//   [1,1,0,1,1,1,1,1,1,1,1,1,1,1],
//   [1,1,0,1,1,1,1,1,1,1,1,1,0,0],
//   [1,1,0,0,0,0,0,0,0,1,1,1,1,1],
//   [0,1,1,1,1,1,1,1,1,1,1,1,1,1],
//   [0,0,0,0,0,0,0,0,0,1,1,1,1,1],
//   [0,1,1,1,1,1,1,1,1,1,1,0,0,0],
//   [0,0,0,1,1,1,1,1,1,1,1,0,0,0],
//   [0,0,0,0,0,0,0,1,1,1,1,0,0,0],
//   [1,1,1,1,1,1,1,1,1,1,0,0,1,1],
//   [1,1,1,0,0,0,1,1,1,1,1,1,1,1],
//   [1,1,1,0,0,0,1,1,1,1,1,1,1,1]
// ]
const frame = [
  [0, 0, 1],
  [0, 1, 0],
  [1, 0, 1],
];

//-----------------------------[input]

const N = frame.length;
const M = frame[0].length;
const direction = [
  [-1, 0],
  [1, 0],
  [0, 1],
  [0, -1],
];
let cnt = 0;

for (let i = 0; i < frame.length; i++) {
  for (let j = 0; j < frame[i].length; j++) {
    let nowX = i;
    let nowY = j;

    const returnVal = recure(N, M, nowX, nowY, frame);
    if (returnVal !== 0) cnt += 1;
  }
}

console.log(cnt);

function recure(N, M, nowX, nowY, frame) {
  if (nowX >= 0 && nowX < N && nowY >= 0 && nowY < M) {
    if (frame[nowX][nowY] === 0) {
      frame[nowX][nowY] = 1;
      return (
        1 +
        recure(N, M, nowX - 1, nowY, frame) +
        recure(N, M, nowX + 1, nowY, frame) +
        recure(N, M, nowX, nowY - 1, frame) +
        recure(N, M, nowX, nowY + 1, frame)
      );
    } else return 0;
  } else return 0;
}

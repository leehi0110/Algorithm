// 풀이 시간 40 => 15:40 - 16:20

// const N = 6;
// const AppleNum = 3;
// const AppLocation = [[], [], [5], [4], [], [3], []];
// const L = 3;
// const Direction = {
//   3: "D",
//   15: "L",
//   17: "D",
// };

// const N = 10;
// const AppleNum = 4;
// const AppLocation = [[], [2, 3, 4, 5], [], [], [], [], [], [], [], [], []];
// const L = 4;
// const Direction = {
//   8: "D",
//   10: "D",
//   11: "D",
//   13: "L",
// };

const N = 10;
const AppleNum = 5;
const AppLocation = [[], [2, 3, 5, 6, 7], [], [], [], [], [], [], [], [], []];
const L = 4;
const Direction = {
  8: "D",
  10: "D",
  11: "D",
  13: "L",
};

//-----------------------------[input]

let snake = [[1, 1]]; // 머리 - 몸통 - 꼬리
let nowDirection = "right";
let time = 0;

while (1) {
  time++;
  let nextX, nextY;
  console.log("now Snake = ", snake);
  console.log("now time ", time);

  if (nowDirection === "right") {
    nextX = snake[0][0] + 1;
    nextY = snake[0][1];
  } else if (nowDirection === "left") {
    nextX = snake[0][0] - 1;
    nextY = snake[0][1];
  } else if (nowDirection === "top") {
    nextX = snake[0][0];
    nextY = snake[0][1] - 1;
  } else {
    // nowDirection === 'bottom'
    nextX = snake[0][0];
    nextY = snake[0][1] + 1;
  }

  console.log("nextX, nextY = ", nextX, " ", nextY);

  for (let [x, y] of snake) {
    if (nextX === x && nextY === y) {
      console.log(time);
      return;
    }
  } // 몸에 부딪히는 경우 종료

  if (nextX === 0 || nextY === 0 || nextX === N + 1 || nextY === N + 1) {
    console.log(time);
    return;
  } // 벽에 부딪히는 경우 종료

  if (nextY in AppLocation[nextX]) {
    AppLocation[nextX].splice(AppLocation[nextX].indexOf(nextY), 1);
    console.log("eat apple and now apple = ", AppLocation);
    // 사과가 존재할 경우 사과를 제거
  } else {
    snake.pop();
    console.log("not apple");
    // 사과가 존재하지 않을 경우 꼬리부분 위치 삭제
  }
  let snakeLen = snake.unshift([nextX, nextY]);
  console.log("snake lenght = ", snakeLen);
  // 머리 부분을 이동

  if (time in Direction) {
    console.log("Before Direction Change ", nowDirection);
    if (Direction[time] === "L") {
      if (nowDirection === "top") {
        nowDirection = "left";
      } else if (nowDirection === "bottom") {
        nowDirection = "right";
      } else if (nowDirection === "left") {
        nowDirection = "bottom";
      } else {
        nowDirection = "top";
      }
    } else {
      // Direction[time] === 'D
      if (nowDirection === "top") {
        nowDirection = "right";
      } else if (nowDirection === "bottom") {
        nowDirection = "left";
      } else if (nowDirection === "left") {
        nowDirection = "top";
      } else {
        nowDirection = "bottom";
      }
    }
    console.log("After Direction Change ", nowDirection);
  }
  console.log("now Snake = ", snake);
}

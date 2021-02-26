// 풀이 시간 20 => 18:40 - 19:00

// const N = 5;
// const Arr = [-15, -6, 1, 3, 7];

// const N = 7;
// const Arr = [-15, -4, 2, 8, 9, 13, 15];

const N = 7;
const Arr = [-15, -4, 3, 8, 9, 13, 15];

//-----------------------------[input]

let start = 0;
let end = Arr.length - 1;
let mid = parseInt((start + end) / 2);

while (1) {
  if (start > end) {
    console.log(-1);
    break;
  }

  if (mid === Arr[mid]) {
    console.log(mid);
    break;
  } else if (mid > Arr[mid]) {
    start = mid + 1;
  } else {
    // mid < Arr[mid]
    end = mid - 1;
  }

  mid = parseInt((start + end) / 2);
}

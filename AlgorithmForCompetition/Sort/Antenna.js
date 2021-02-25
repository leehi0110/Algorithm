// 풀이 시간 20 => 19:10 - 19:30

const N = 4;
const house = [5, 1, 7, 9];

// const N = 6;
// const house = [1, 2, 3, 5, 8, 9];
//-----------------------------[input]

house.sort((a, b) => a - b);

if (house.length % 2 === 0) {
  let left_mid = parseInt(house.length / 2) - 1;
  let right_mid = parseInt(house.length / 2);

  let left_dis = house[left_mid] - house[0] + house[N - 1] - house[left_mid];
  let rigth_dis = house[right_mid] - house[0] + house[N - 1] - house[right_mid];

  if (left_dis > rigth_dis) console.log(house[right_mid]);
  else console.log(house[left_mid]);
} else console.log(house[parseInt(house.length / 2)]);

// ----------------- 책의 풀이
// 단순히 중간값 많을 계산

// house.sort((a, b) => a - b);
// console.log(house[parseInt(house.length / 2 - 1)]);

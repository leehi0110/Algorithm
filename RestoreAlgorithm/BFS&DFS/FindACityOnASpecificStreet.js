// case 1:
const city = 4;
const street = 4;
const K = 2;
const X = 1;
const cities = [[], [2, 3], [3, 4], [], []];

// // case 2:
// const city = 4;
// const street = 3;
// const K = 2;
// const X = 1;
// const cities = [[], [2, 3, 4], [], [], []];

// // case 3:
// const city = 4;
// const street = 4;
// const K = 1;
// const X = 1;
// const cities = [[], [2, 3], [3, 4], [], []];

let distance = Array.from({ length: city + 1 }, () => Infinity);
distance[X] = 0;

checkDistance(cities, X, distance);

function checkDistance(cities, start, distance) {
  for (let c of cities[start]) {
    if (distance[c] > 1 + distance[start]) {
      distance[c] = 1 + distance[start];
      checkDistance(cities, c, distance);
    }
  }
}

if (!distance.includes(K)) console.log(-1);
else {
  for (let i = 0; i < distance.length; i++) {
    if (distance[i] === K) console.log(i);
  }
}

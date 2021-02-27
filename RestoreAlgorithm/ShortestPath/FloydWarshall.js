const N = 4;
const M = 7;

const distance = Array.from(Array(4), () => Array(4).fill(Infinity));

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    if (i === j) distance[i][j] = 0;
  }
}

distance[0][1] = 4;
distance[0][3] = 6;
distance[1][0] = 3;
distance[1][2] = 7;
distance[2][0] = 5;
distance[2][3] = 4;
distance[3][2] = 2;

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    for (let k = 0; k < N; k++) {
      distance[i][j] = Math.min(
        distance[i][j],
        distance[i][k] + distance[k][j]
      );
    }
  }
}

for (let i = 0; i < N; i++) {
  console.log(distance[i]);
}

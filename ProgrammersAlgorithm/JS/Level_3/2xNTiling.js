function solution(n) {
  let d = Array.from({ length: 60001 }, () => 0);

  d[1] = 1;
  d[2] = 2;

  for (let i = 3; i <= n; i++) {
    d[i] = (d[i - 1] + d[i - 2]) % 1000000007;
  }

  return d[n];
}

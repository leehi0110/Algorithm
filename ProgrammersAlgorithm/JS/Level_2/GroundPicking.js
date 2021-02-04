function solution(land) {
  var answer = 0;
  let dp = Array.from(Array(land.length), () => Array(4).fill(0));

  for(let i=0;i<4;i++) {
    dp[0][i] = land[0][i];
  }

  for(let i=1;i<land.length;i++) {
    dp[i][0] = Math.max(dp[i-1][1], dp[i-1][2], dp[i-1][3]) + land[i][0];
    dp[i][1] = Math.max(dp[i-1][0], dp[i-1][2], dp[i-1][3]) + land[i][1];
    dp[i][2] = Math.max(dp[i-1][0], dp[i-1][1], dp[i-1][3]) + land[i][2];
    dp[i][3] = Math.max(dp[i-1][0], dp[i-1][1], dp[i-1][2]) + land[i][3];
  }

  return Math.max(...dp[land.length-1]);
}
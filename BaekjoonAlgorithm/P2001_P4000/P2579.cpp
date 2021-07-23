// ProblemNumber || ProblemName : P2579 - 계단 오르기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  vector<int> score(n + 1);
  vector<vector<int>> dp(n + 1, vector<int>(2, 0));

  for (int i = 1; i <= n; i++)
  {
    int point;
    cin >> point;
    score[i] = point;
  }

  // dp[x][0] = 1칸전 밟고 올라온 경우
  // dp[x][1] = 2칸전에서 뛰어 올라온 경우

  dp[0][0] = 0;
  dp[0][1] = 0;

  dp[1][0] = score[1];
  dp[1][1] = score[1];

  for (int i = 2; i <= n; i++)
  {
    dp[i][0] = dp[i - 1][1] + score[i];
    dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + score[i];
  }

  cout << max(dp[n][0], dp[n][1]) << endl;
}

// ProblemNumber || ProblemName : P11048 - 이동하기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int map[1001][1001];
int dp[1001][1001];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
    }
  }

  dp[0][0] = map[0][0];

  for (int i = 1; i < m; i++)
  {
    dp[0][i] = map[0][i] + dp[0][i - 1];
  }

  for (int i = 1; i < n; i++)
  {
    dp[i][0] = map[i][0] + dp[i - 1][0];
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      int maxCandy = dp[i - 1][j - 1];
      maxCandy = max(maxCandy, dp[i][j - 1]);
      maxCandy = max(maxCandy, dp[i - 1][j]);

      dp[i][j] = maxCandy + map[i][j];
    }
  }

  cout << dp[n - 1][m - 1] << endl;
}
// ProblemNumber || ProblemName : P1010 - 다리 놓기
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 점화식을 세우기 위해 원리를 정확히 파악하는 것이 중요하다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp[31][31];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  for (int i = 1; i <= 30; i++)
  {
    dp[1][i] = i;
    dp[i][i] = 1;
  }

  for (int i = 2; i <= 30; i++)
  {
    for (int j = i; j <= 30; j++)
    {
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
    }
  }

  // dp[n][m] = dp[n][m-1] + dp[n-1][m-1];

  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;

    cout << dp[a][b] << endl;
  }
}
// ProblemNumber || ProblemName : P12865 - 평범한 배낭
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int dp[101][100001];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;

  cin >> n >> k;
  vector<pair<int, int>> gem(n + 1);

  for (int i = 1; i <= n; i++)
  {
    cin >> gem[i].first;
    cin >> gem[i].second;
  }

  for (int i = 1; i <= n; i++)
  {
    int weight = gem[i].first;
    int value = gem[i].second;

    for (int j = 1; j <= k; j++)
    {
      if (weight <= j)
      {
        dp[i][j] = max(value + dp[i - 1][j - weight], dp[i - 1][j]);
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n][k] << endl;
}

// ProblemNumber || ProblemName : P2156 - 포도주 시식
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  vector<int> cup(n + 1, 0);
  vector<vector<int>> dp(n + 1, vector<int>(3, 0));

  for (int i = 1; i <= n; i++)
  {
    cin >> cup[i];
  }

  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;

  dp[1][0] = 0;
  dp[1][1] = cup[1];
  dp[1][2] = cup[1];

  for (int i = 2; i <= n; i++)
  {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = *max_element(dp[i - 2].begin(), dp[i - 2].end()) + cup[i];
    dp[i][2] = dp[i - 1][1] + cup[i];
  }

  cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
}

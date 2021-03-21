// ProblemNumber || ProblemName : 1535 - 안녕

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

  vector<int> health(n);
  vector<int> happy(n);
  vector<vector<int>> dp(n + 1, vector<int>(101, 0));

  for (int i = 0; i < n; i++)
  {
    cin >> health[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> happy[i];
  }

  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < 100; j++)
    {
      if (health[i - 1] <= j)
      {
        dp[i][j] = max(dp[i - 1][j], happy[i - 1] + dp[i - 1][j - health[i - 1]]);
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  auto it = max_element(dp[n].begin(), dp[n].end());
  cout << *it << endl;
}
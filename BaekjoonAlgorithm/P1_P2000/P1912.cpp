// ProblemNumber || ProblemName : P1912 - 연속 합
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int maxSum;
  vector<int> number;
  vector<vector<int>> dp;

  cin >> n;

  number.resize(n);
  dp.resize(n);

  for (int i = 0; i < n; i++)
  {
    dp[i].resize(2, 0);
  }

  for (int i = 0; i < n; i++)
  {
    cin >> number[i];
  }

  dp[0][0] = number[0];
  dp[0][1] = number[0];
  maxSum = number[0];

  for (int i = 1; i < n; i++)
  {
    dp[i][0] = number[i];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + number[i];

    if (dp[i][0] > maxSum)
      maxSum = dp[i][0];
    if (dp[i][1] > maxSum)
      maxSum = dp[i][1];
  }

  cout << maxSum << endl;
}

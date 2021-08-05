// ProblemNumber || ProblemName : P9465 - 스티커
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int testCase;
int cardNum;

void solve();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    solve();
  }
}

void solve()
{
  cin >> cardNum;
  vector<vector<int>> card(2, vector<int>(cardNum + 1, 0));
  vector<vector<int>> dp(2, vector<int>(cardNum + 1, 0));

  for (int i = 0; i < 2; i++)
  {
    for (int j = 1; j <= cardNum; j++)
    {
      cin >> card[i][j];
    }
  }

  dp[0][1] = card[0][1];
  dp[1][1] = card[1][1];

  // 00 01 02 03 04 05 06
  // 10 11 12 13 14 15 16

  for (int i = 2; i <= cardNum; i++)
  {
    dp[0][i] = max(max(dp[0][i - 2], dp[1][i - 2]), dp[1][i - 1]) + card[0][i];
    dp[1][i] = max(max(dp[0][i - 2], dp[1][i - 2]), dp[0][i - 1]) + card[1][i];
  }

  cout << max(dp[0][cardNum], dp[1][cardNum]) << endl;
}

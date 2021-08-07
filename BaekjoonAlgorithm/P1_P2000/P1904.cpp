// ProblemNumber || ProblemName : P1904 - 01타일
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[1000001];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; i++)
  {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
  }

  cout << dp[n] << endl;
}

// ProblemNumber || ProblemName : 2747 - 피보나치 수

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> dp(50, 0);
  int n;

  cin >> n;

  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << dp[n] << endl;
}

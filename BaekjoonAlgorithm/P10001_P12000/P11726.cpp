// ProblemNumber || ProblemName : P11726 - 2 x n 타일링
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; i++)
  {
    dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
  }
  cout << dp[n] << endl;
}

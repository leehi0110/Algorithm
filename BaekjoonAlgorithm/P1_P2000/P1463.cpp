// ProblemNumber || ProblemName : P1463 - 1로 만들기
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 예외 케이스에 대해 깊이 생각해봐야 된다.
// -> 2로 나눠지는 경우, 3으로 나눠지는 경우만 생각한다면 if & else if를 사용하면 되지만,
// -> 6과 같이 2와 3으로 모두 나누어 떨어지는 경우가 있기 때문에 if & if로 처리해야 된다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000001];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  dp[1] = 0;

  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + 1;
    if (i % 3 == 0)
    {
      dp[i] = min(dp[i / 3] + 1, dp[i]);
    }
    if (i % 2 == 0)
    {
      dp[i] = min(dp[i / 2] + 1, dp[i]);
    }
  }

  cout << dp[n] << endl;
}

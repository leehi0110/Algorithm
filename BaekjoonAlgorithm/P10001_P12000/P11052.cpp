// ProblemNumber || ProblemName : P11052 - 카드 구매하기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cardPrice[1001];
int dp[1001];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> cardPrice[i];
    dp[i] = cardPrice[i];
  }

  dp[2] = max(cardPrice[2], dp[1] + dp[1]);

  for (int i = 2; i <= n; i++)
  {
    int a = i - 1;
    int b = 1;

    while (a >= b)
    {
      dp[i] = max(dp[i], dp[a] + dp[b]);
      a--;
      b++;
    }
  }

  cout << dp[n] << endl;
}

// 1개
// 1
// 2개
// 2 / 1 1
// 3개
// 3 / 2 1
// 4개
// 4 / 3 1 / 2 2
// 5개
// 5 / 4 1 / 3 2
// 6개
// 6 / 5 1 / 4 2 / 3 3
// 7개
// 7 / 6 1 / 5 2 / 4 3

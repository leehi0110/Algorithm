// ProblemNumber || ProblemName : P11057 - 오르막 수
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[1001][10];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < 10; i++)
  {
    dp[0][i] = 0;
    dp[1][i] = 1;
  }

  for (int i = 0; i < 10; i++)
  {
    dp[2][i] = 10 - i;
  }

  for (int i = 3; i <= n; i++)
  {
    int sum = 0;
    for (int j = 9; j > -1; j--)
    {
      dp[i][j] = sum + dp[i - 1][j];
      sum = (sum + dp[i - 1][j]) % 10007;
    }
  }

  int result = 0;

  for (int i = 0; i < 10; i++)
  {
    result = (result + dp[n][i]) % 10007;
  }

  cout << result << endl;
}

// dp[자리수][시작자리] = dp[자리수 - 1] * (10 - 시작자리)

// 1 = 10개
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9

// 2 = 55 개
// 00 01 02 03 04 05 06 07 08 09
//    11 12 13 14 15 16 17 18 19
//       22 23 24 25 26 27 28 29
//          33 34 35 36 37 38 39
//             44 45 46 47 48 49
//                55 56 57 58 59
//                   66 67 68 69
//                      77 78 79
//                         88 89
//                            99

// 3 = 220
// 550 + 45 * 9
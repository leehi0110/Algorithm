// ProblemNumber || ProblemName : P2193 - 이친수
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 90자리가 들어올 경우 int의 개수로는 담을 수 없기 때문에 long long을 써야한다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[91];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 2] + dp[i - 1];
  }

  cout << dp[n - 1] << endl;
}

// 2^0
// 1
// 1
// 1개

// 2^1
// 2  3
// 10 11
// 1개

// 2^2
// 4   5   6   7
// 100 101 110 111
// 2개

// 2^3
// 8     9     10    11   12   13   14   15
// 1000  1001  1010  1011 1100 1101 1110 1111
// 3

// 2^4
// 16    17    18    19    20    21    22    23    24    25    26    27    28    29    30    31
// 10000 10001 10010 10011 10100 10101 10110 10111 11000 11001 11010 11011 11100 11101 11110 111111
// 5
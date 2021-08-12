// ProblemNumber || ProblemName : P2520 - 떡 먹는 호랑이
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
typedef long long ll;

using namespace std;

vector<pair<ll, ll>> dp(31, make_pair(0, 0));

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  ll total;

  cin >> n;
  cin >> total;

  dp[0] = {0, 0};
  dp[1] = {1, 0};
  dp[2] = {0, 1};

  for (int i = 3; i <= 30; i++)
  {
    dp[i].first = dp[i - 1].first + dp[i - 2].first;
    dp[i].second = dp[i - 1].second + dp[i - 2].second;
  }

  ll x = 1;

  while (1)
  {
    ll xCnt = dp[n].first * x;

    if ((total - xCnt) % dp[n].second == 0)
    {
      cout << x << endl;
      cout << (total - xCnt) / dp[n].second << endl;
      break;
    }
    else
    {
      x++;
    }
  }
}

// 6일 41

// 1일 x
// 2일 y
// 3일 = x + y
// 4일 = x + 2y
// 5일 = 2x + 3y
// 6일 = 3x + 5y
// 7일 = 5x + 8y

// t일 = t-2일 + t-1일
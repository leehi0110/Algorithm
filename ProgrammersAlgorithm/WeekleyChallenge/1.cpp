#include <vector>
#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
  vector<long long> dp(count + 1, 0);

  dp[0] = 0;
  dp[1] = static_cast<long long>(price);

  for (int i = 2; i <= count; i++)
  {
    dp[i] = dp[i - 1] + static_cast<long long>(price) * i;
  }

  return static_cast<long long>(money) >= dp[count] ? 0 : dp[count] - static_cast<long long>(money);
}

int main()
{
  long long result = solution(3, 20, 4);

  cout << result << endl;
}
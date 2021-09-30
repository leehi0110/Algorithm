// ProblemNumber || ProblemName : P1747 - 소수&팰린드롬
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

bool isPalindrome(int number);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  vector<bool> primes(2000000, true);

  primes[0] = false;
  primes[1] = false;

  for (int i = 2; i < primes.size(); i++)
  {
    if (primes[i])
    {
      for (int j = i * 2; j < primes.size(); j += i)
        primes[j] = false;
    }
  }

  int n;

  cin >> n;

  while (1)
  {
    if (primes[n] && isPalindrome(n))
    {
      cout << n << endl;
      break;
    }
    else
      n++;
  }
}

bool isPalindrome(int number)
{
  string strNum = to_string(number);
  string reverseStr = "";

  for (int i = strNum.length() - 1; i >= 0; i--)
  {
    reverseStr += strNum[i];
  }

  if (strNum == reverseStr)
    return true;
  else
    return false;
}
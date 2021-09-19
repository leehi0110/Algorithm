// ProblemNumber || ProblemName : P5636 - 소수 부분 문자열
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  vector<bool> primes(100001, true);

  primes[0] = false;
  primes[1] = false;

  for (int i = 2; i < 100001; i++)
  {
    if (primes[i])
    {
      for (int j = i * 2; j < 100001; j += i)
      {
        primes[j] = false;
      }
    }
  }

  while (1)
  {
    string numStr;
    int len, maxLen;

    cin >> numStr;

    if (numStr == "0")
      break;

    len = numStr.length();
    maxLen = len > 6 ? 6 : len;

    // 11245 -> maxLen = 5, len = 5

    for (int i = maxLen; i > 0; i--)
    {
      int maxPrime = -1;
      for (int j = len - maxLen; j >= 0; j--)
      {

        string subNumStr = numStr.substr(j, i);
        int subNum = stoi(subNumStr);

        if (subNum > 100001)
          continue;

        if (primes[subNum] && maxPrime < subNum)
        {
          maxPrime = subNum;
        }
      }

      if (maxPrime != -1)
      {
        cout << maxPrime << endl;
        break;
      }
    }
  }
}

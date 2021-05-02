// ProblemNumber || ProblemName : P1107 - 리모콘

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int target, n, answer;
  int plusCnt, leftCnt = INF, rightCnt = INF;
  vector<bool> broken(10, true);

  cin >> target;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;

    broken[num] = false;
  }

  if (target > 100)
    plusCnt = target - 100;
  else
    plusCnt = 100 - target;

  for (int i = target; i < 1000000; i++)
  {
    string s_num = to_string(i);

    for (int j = 0; j < s_num.length(); j++)
    {
      int num = s_num[j] - '0';

      if (!broken[num])
        break;

      if (j == s_num.length() - 1)
      {
        rightCnt = s_num.length() + i - target;
      }
    }

    if (rightCnt != INF)
      break;
  }

  for (int i = target - 1; i >= 0; i--)
  {
    string s_num = to_string(i);

    for (int j = 0; j < s_num.length(); j++)
    {
      int num = s_num[j] - '0';

      if (!broken[num])
        break;

      if (j == s_num.length() - 1)
      {
        leftCnt = s_num.length() + target - i;
      }
    }

    if (leftCnt != INF)
      break;
  }

  answer = min(plusCnt, leftCnt);
  answer = min(answer, rightCnt);

  cout << answer << endl;
}
// ProblemNumber || ProblemName : P9935 - 문자열 폭발
// 하면서 좀 더 깊게 생각하게 된 것들
// -> erase()보다 pop_back()을 이용해 시간을 단축시킬 수 있다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  string target;
  string result = "";

  cin >> str;
  cin >> target;

  int targetLen = target.length() - 1;

  for (int i = 0; i < str.length(); i++)
  {

    result += str[i];

    if (result[result.length() - 1] == target[targetLen])
    {
      int cnt = 1;
      for (int j = targetLen - 1; j >= 0; j--)
      {
        if (result[result.length() - 1 - (targetLen - j)] != target[j])
          break;

        cnt++;
      }

      if (cnt == targetLen + 1)
      {
        for (int j = 0; j < targetLen + 1; j++)
        {
          result.pop_back();
        }
      }
    }
  }

  if (result.length() == 0)
    cout << "FRULA" << endl;
  else
    cout << result << endl;
}

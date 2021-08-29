// ProblemNumber || ProblemName : P12904 - A와 B
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

  string str, target;
  bool ptr = true;
  // true = 정순
  // false = 역순

  cin >> str;
  cin >> target;

  while (1)
  {

    if (target.length() == str.length())
    {
      string result = "";

      if (!ptr)
      {
        for (int i = target.length() - 1; i >= 0; i--)
        {
          result += target[i];
        }
      }
      else
        result = target;

      if (result == str)
        cout << 1 << endl;
      else
        cout << 0 << endl;
      break;
    }

    if (ptr)
    {
      if (target[target.length() - 1] == 'B')
      {
        ptr = !ptr;
      }
      target = target.substr(0, target.length() - 1);
    } // 정 방향
    else
    {
      if (target[0] == 'B')
      {
        ptr = !ptr;
      }
      target = target.substr(1);
    } // 역 방향
  }
}

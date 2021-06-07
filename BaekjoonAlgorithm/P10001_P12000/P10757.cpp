// ProblemNumber || ProblemName : P10757 - 큰 수 A + B
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 범위가 큰 수 일 경우 데이터 타입의 문제가 아닌 문자열로 해결하는 방법을 생각하자

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  string a;
  string b;
  string result = "";
  stack<char> aStack;
  stack<char> bStack;

  int up = 0;

  cin >> a >> b;

  for (int i = 0; i < a.length(); i++)
  {
    aStack.push(a[i]);
  }

  for (int i = 0; i < b.length(); i++)
  {
    bStack.push(b[i]);
  }

  while (!aStack.empty() || !bStack.empty())
  {
    if (aStack.empty())
    {
      char temp = bStack.top();
      bStack.pop();

      if (temp - '0' + up > 9)
      {
        result += to_string(((temp - '0') + up) % 10);
        up = 1;
      }
      else
      {
        result += to_string((temp - '0') + up);
        up = 0;
      }
    }
    else if (bStack.empty())
    {
      char temp = aStack.top();
      aStack.pop();

      if (temp - '0' + up > 9)
      {
        result += to_string(((temp - '0') + up) % 10);
        up = 1;
      }
      else
      {
        result += to_string((temp - '0') + up);
        up = 0;
      }
    }
    else
    {

      int aNum = aStack.top() - '0';
      int bNum = bStack.top() - '0';

      aStack.pop();
      bStack.pop();

      if (aNum + bNum + up > 9)
      {
        result += to_string((aNum + bNum + up) % 10);
        up = 1;
      }
      else
      {
        result += to_string(aNum + bNum + up);
        up = 0;
      }
    }
  }

  if (up == 1)
    result += '1';

  for (int i = result.length() - 1; i >= 0; i--)
  {
    cout << result[i];
  }
  cout << endl;
}

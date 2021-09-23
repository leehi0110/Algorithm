// ProblemNumber || ProblemName : P13235 - 팰린드롬
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

  string str;
  string result = "true";
  cin >> str;

  int start = 0;
  int end = str.length() - 1;

  while (start <= end)
  {
    if (str[start] == str[end])
    {
      start++;
      end--;
    }
    else
    {
      result = "false";
      break;
    }
  }

  cout << result << endl;
}

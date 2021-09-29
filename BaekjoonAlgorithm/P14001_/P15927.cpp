// ProblemNumber || ProblemName : P15927 - 회문은 회문이 아니야!
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 재귀를 통해 글자를 줄여나갈 필요없이 모든 문자가 같은 경우, 팰린드롬인 경우, 팰린드롬이 아닌 경우만 따져서 결과를 출력할 수 있다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

bool isPalindrom(string s);
bool isSame(string s);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  string s;

  cin >> s;

  if (isPalindrom(s))
  {
    if (isSame(s))
      cout << -1 << endl;
    else
      cout << s.length() - 1 << endl;
  }
  else
  {
    cout << s.length() << endl;
  }
}

bool isSame(string s)
{
  char temp = s[0];

  for (int i = 1; i < s.length(); i++)
  {
    if (s[i] == temp)
      continue;
    else
      return false;
  }

  return true;
}

bool isPalindrom(string s)
{
  int startIdx = 0;
  int endIdx = s.length() - 1;

  while (startIdx <= endIdx)
  {
    if (s[startIdx] == s[endIdx])
    {
      startIdx++;
      endIdx--;
    }
    else
    {
      return false;
    }
  }

  return true;
}

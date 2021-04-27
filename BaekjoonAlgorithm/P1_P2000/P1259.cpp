// ProblemNumber || ProblemName : P1259 - 팰린드롬 수

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  while (1)
  {
    string s;
    cin >> n;

    if (n == 0)
      break;

    s = to_string(n);
    for (int i = 0, j = s.length() - 1;; i++, j--)
    {
      if (s[i] != s[j])
      {
        cout << "no" << endl;
        break;
      }

      if (i >= j)
      {
        cout << "yes" << endl;
        break;
      }
    }
  }
}

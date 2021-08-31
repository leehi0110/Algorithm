// ProblemNumber || ProblemName : P9081 - 단어 맞추기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

void solve();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    solve();
  }
}

void solve()
{
  string str;
  string front = "";
  string back = "";
  int minGap = 100;
  string minChar = "";
  int targetIdx;
  char targetChar;

  cin >> str;

  for (int i = str.length() - 1; i > 0; i--)
  {
    if (str[i] > str[i - 1])
    {
      targetIdx = i - 1;
      targetChar = str[i - 1];
      front = str.substr(0, i - 1);
      break;
    }
  }

  if (front == "" && targetIdx != 0)
  {
    cout << str << endl;
  }
  else
  {
    for (int i = targetIdx; i < str.length(); i++)
    {
      if (targetChar < str[i] && str[i] - targetChar < minGap)
      {
        if (minChar != "")
        {
          back += minChar;
        }
        minChar = str[i];
        minGap = str[i] - targetChar;
      }
      else
      {
        back += str[i];
      }

      if (i == str.length() - 1)
        front += minChar;
    }

    sort(back.begin(), back.end());

    cout << front << back << endl;
  }
}

// 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6
// a b c d e f g h i j k l m n o p q r s t u v w x y z

// HELLO                |   HELOL
// 8 5 12 12 15         |   8 5 12 15 12
// DRINK                |   DRKIN
// 4 18 9 14 11         |   4 18 11 9 14
// S HUTTLE             |   S LEHTTU
// 19 8 21 20 20  12 5  |   19 12 5 8 20 20 21
// ZOO                  |   ZOO
// 26 15 15             |   26 15 15
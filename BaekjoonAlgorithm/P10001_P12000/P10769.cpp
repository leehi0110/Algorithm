// ProblemNumber || ProblemName : P10769 - 행복한지 슬픈지

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  string s;

  int happy = 0;
  int sad = 0;

  getline(cin, s);

  for (int i = 0; i < s.length() - 2; i++)
  {
    if (s[i] == ':' && s[i + 1] == '-' && s[i + 2] == ')')
      happy++;
    else if (s[i] == ':' && s[i + 1] == '-' && s[i + 2] == '(')
      sad++;
  }

  if (happy == 0 && sad == 0)
    cout << "none" << endl;
  else if (happy == sad)
    cout << "unsure" << endl;
  else if (happy > sad)
    cout << "happy" << endl;
  else
    cout << "sad" << endl;
}

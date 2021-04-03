#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string s)
{
  int answer = 0;
  vector<string> vc;

  for (int i = 0; i < s.length(); i++)
  {
    string tmp = "";
    vector<bool> alph(26, false);

    for (int j = i; j < s.length(); j++)
    {

      if (!alph[s[j] - 97])
      { // 없는 경우
        alph[s[j] - 97] = true;
      }
      else
      {
        break;
      }

      tmp += s[j];
      if (find(vc.begin(), vc.end(), tmp) == vc.end())
      {
        vc.push_back(tmp);
      }
    }
  }

  for (int i = 0; i < vc.size(); i++)
  {
    cout << vc[i] << " ";
  }
  cout << endl;

  return vc.size();
}

int main()
{
  cout << solution("abcd") << endl;
}
// ProblemNumber || ProblemName : P10798 - 세로 읽기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<char>> table(5);
  int maxLen = 0;
  string answer = "";

  for (int i = 0; i < 5; i++)
  {
    string temp;
    getline(cin, temp);

    if (temp.length() > maxLen)
      maxLen = temp.length();

    for (int j = 0; j < temp.length(); j++)
    {
      table[i].push_back(temp[j]);
    }
  }

  for (int i = 0; i < maxLen; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (table[j].size() > i)
      {
        answer += table[j][i];
      }
    }
  }

  cout << answer << endl;
}

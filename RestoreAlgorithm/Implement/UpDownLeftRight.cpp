// ProblemNumber || ProblemName : 상하좌우

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int N;
  int x = 1, y = 1;
  string cmds;
  vector<char> cmd;

  cin >> N;
  cin.ignore();
  getline(cin, cmds);

  for (int i = 0; i < cmds.size(); i++)
  {
    if (cmds[i] != ' ')
      cmd.push_back(cmds[i]);
  }

  for (auto c : cmd)
  {
    if (c == 'R')
    {
      if (x != N)
        x++;
    }
    else if (c == 'L')
    {
      if (x != 1)
        x--;
    }
    else if (c == 'U')
    {
      if (y != 1)
        y--;
    }
    else if (c == 'D')
    {
      if (y != N)
        y++;
    }
  }

  cout << y << " " << x << endl;
}

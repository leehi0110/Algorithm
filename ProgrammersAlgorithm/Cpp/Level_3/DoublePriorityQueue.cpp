#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations)
{
  multiset<int> table;

  for (int i = 0; i < operations.size(); i++)
  {
    vector<string> cmd;
    stringstream ss(operations[i]);
    string temp;

    while (getline(ss, temp, ' '))
    {
      cmd.push_back(temp);
    }

    if (cmd[0] == "I")
    {
      table.insert(stoi(cmd[1]));
    }
    else // cmd[0] == 'D'
    {
      if (table.size() == 0)
        continue;
      else
      {
        if (cmd[1] == "-1")
        {
          table.erase(table.begin());
        }
        else
        {
          table.erase(--table.end());
        }
      }
    }
  }

  if (table.size() == 0)
  {
    return {0, 0};
  }
  else
  {
    auto begin = table.begin();
    auto end = --table.end();
    return {*end, *begin};
  }
}
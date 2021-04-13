#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n)
{
  vector<int> answer;
  vector<vector<int>> table(n, vector<int>(n));

  int number = 1;
  int cnt = n;
  int flag = 1;
  int x = 0, y = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = cnt; j > 0; j--)
    {
      table[x][y] = number++;
      if (flag == 1)
      {
        if (j - 1 == 0)
        {
          y++;
        }
        else
        {
          x++;
        }
      }
      else if (flag == 2)
      {
        if (j - 1 == 0)
        {
          x--;
          y--;
        }
        else
          y++;
      }
      else if (flag == 3)
      {
        if (j - 1 == 0)
        {
          x++;
        }
        else
        {
          x--;
          y--;
        }
      }
    }

    cnt--;
    flag = (flag % 3) + 1;
  }

  for (int i = 0; i < table.size(); i++)
  {
    for (int j = 0; j < table.size(); j++)
    {
      if (table[i][j] == 0)
        break;
      else
      {
        answer.push_back(table[i][j]);
      }
    }
  }

  return answer;
}

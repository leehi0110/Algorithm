// ProblemNumber || ProblemName : P14503 - 로봇 청소기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  bool flag = false;
  int nowX, nowY, direction;
  int result = 0;

  cin >> n >> m;
  cin >> nowX >> nowY >> direction;

  vector<vector<int>> table(n, vector<int>(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> table[i][j];
    }
  }

  while (1)
  {

    if (table[nowX][nowY] == 0)
    {
      table[nowX][nowY] = 2;
      result++;
    }
    else
    {
      for (int i = 0; i < 4; i++)
      {
        if (table[nowX + dx[(direction + 3 - i) % 4]][nowY + dy[(direction + 3 - i) % 4]] == 0)
        {

          nowX += dx[(direction + 3 - i) % 4];
          nowY += dy[(direction + 3 - i) % 4];
          direction = (direction + 3 - i) % 4;
          break;
        }

        if (i == 3)
        {
          if (table[nowX + dx[(direction + 2) % 4]][nowY + dy[(direction + 2) % 4]] != 1)
          {
            nowX += dx[(direction + 2) % 4];
            nowY += dy[(direction + 2) % 4];
          }
          else
          {
            flag = !flag;
          }
        }
      }
    }

    if (flag)
      break;
  }

  cout << result << endl;
}

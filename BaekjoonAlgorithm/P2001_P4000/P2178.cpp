// ProblemNumber || ProblemName : P2178 - 미로 탐색

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
void BFS(vector<vector<int>> &map, int x, int y, int step);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  vector<vector<int>> map(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
  {
    string tmp;
    cin >> tmp;

    for (int j = 0; j < tmp.size(); j++)
    {
      map[i][j] = tmp[j] - '0';
    }
  }

  BFS(map, 0, 0, 1);

  cout << map[n - 1][m - 1] << endl;
}

void BFS(vector<vector<int>> &map, int x, int y, int step)
{

  if (x == n - 1 && y == m - 1)
  {
    if (map[x][y] == 1)
    {
      map[x][y] = step;
    }
    else
    {
      int minStep = map[x][y];
      if (step < minStep)
      {
        map[x][y] = step;
      }
    }
  }
  else if (x < 0 || y < 0 || x >= n || y >= m)
    return;
  else if (map[x][y] == 0)
    return;
  else
  {
    if (map[x][y] == 1)
    {
      map[x][y] = step;
      BFS(map, x - 1, y, step + 1);
      BFS(map, x + 1, y, step + 1);
      BFS(map, x, y - 1, step + 1);
      BFS(map, x, y + 1, step + 1);
    }
    else
    {
      int minStep = map[x][y];
      if (step < minStep)
      {
        map[x][y] = step;
        BFS(map, x - 1, y, step + 1);
        BFS(map, x + 1, y, step + 1);
        BFS(map, x, y - 1, step + 1);
        BFS(map, x, y + 1, step + 1);
      }
    }
  }
}

// ProblemNumber || ProblemName : 1012 - 유기농 배추

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void bfs(vector<vector<int>> &ground, int x, int y, int n, int m);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testcase;

  cin >> testcase;

  for (int i = 0; i < testcase; i++)
  {
    int n, m, k;
    int cnt = 0;

    cin >> m >> n >> k;

    vector<vector<int>> ground(n, vector<int>(m, 0));

    for (int j = 0; j < k; j++)
    {
      int x, y;
      cin >> x >> y;

      ground[y][x] = 1;
    }

    if (k <= 1)
      cout << k << endl;
    else
    {
      for (int a = 0; a < n; a++)
      {
        for (int b = 0; b < m; b++)
        {
          if (ground[a][b] == 1)
          {
            cnt++;
            bfs(ground, a, b, n, m);
          }
        }
      }
      cout << cnt << endl;
    }
  }
}

void bfs(vector<vector<int>> &ground, int x, int y, int n, int m)
{
  if (x < 0 || x >= n || y < 0 || y >= m)
    return;
  else
  {
    if (ground[x][y] == 1)
    {
      ground[x][y] = 0;
      bfs(ground, x - 1, y, n, m);
      bfs(ground, x + 1, y, n, m);
      bfs(ground, x, y + 1, n, m);
      bfs(ground, x, y - 1, n, m);
    }
    else
      return;
  }
}

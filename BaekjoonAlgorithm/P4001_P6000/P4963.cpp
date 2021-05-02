// ProblemNumber || ProblemName : P4963 - 섬의 개수

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int BFS(vector<vector<int>> map);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  while (1)
  {
    int w, h;

    cin >> w >> h;

    if (w == 0 && h == 0)
      break;

    vector<vector<int>> map(h, vector<int>(w, 0));

    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        int a;
        cin >> a;

        map[i][j] = a;
      }
    }

    cout << BFS(map) << endl;
  }
}

int BFS(vector<vector<int>> map)
{
  queue<pair<int, int>> que;
  int cnt = 0;

  for (int i = 0; i < map.size(); i++)
  {
    for (int j = 0; j < map[i].size(); j++)
    {
      if (map[i][j] == 1)
      {
        cnt++;
        map[i][j] = 0;

        for (int k = 0; k < 8; k++)
        {
          int nx = i + dx[k];
          int ny = j + dy[k];

          if (nx < 0 || nx >= map.size() || ny < 0 || ny >= map[0].size())
            continue;
          if (map[nx][ny] == 0)
            continue;

          que.push({nx, ny});
        }

        while (!que.empty())
        {
          int x = que.front().first;
          int y = que.front().second;
          que.pop();

          if (map[x][y] == 0)
            continue;
          map[x][y] = 0;

          for (int k = 0; k < 8; k++)
          {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= map.size() || ny < 0 || ny >= map[0].size())
              continue;
            if (map[nx][ny] == 0)
              continue;

            que.push({nx, ny});
          }
        }
      }
    }
  }

  return cnt;
}

#include <vector>
#include <utility>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int solution(vector<vector<int>> maps)
{
  queue<pair<int, int>> que;

  que.push({0, 0});

  while (!que.empty())
  {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size())
        continue;
      if (maps[nx][ny] == 0)
        continue;

      if (maps[nx][ny] == 1)
      {
        maps[nx][ny] = maps[x][y] + 1;
        que.push({nx, ny});
      }
    }
  }

  return maps[maps.size() - 1][maps[0].size() - 1] == 1 ? -1 : maps[maps.size() - 1][maps[0].size() - 1];
}

int main()
{
  // int result = solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}});
  int result = solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}});

  cout << result << endl;
}
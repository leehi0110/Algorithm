// ProblemNumber || ProblemName : P14940 - 쉬운 최단거리
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int map[1001][1001];
// int distMap[1001][1001];
pair<int, int> target = {0, 0};

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  priority_queue<pair<int, pair<int, int>>> pq;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int temp;
      cin >> temp;

      if (temp == 2)
      {
        target = {i, j};
        map[i][j] = 0;
      }
      else if (temp == 1)
      {
        map[i][j] = INF;
      }
      else
      {
        map[i][j] = 0;
      }
    }
  }

  pq.push({0, {target.first, target.second}});

  while (!pq.empty())
  {
    int dist = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    for (int i = 0; i < 4; i++)
    {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= m || map[moveX][moveY] <= dist + 1)
        continue;

      map[moveX][moveY] = dist + 1;
      pq.push({-map[moveX][moveY], {moveX, moveY}});
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (map[i][j] == INF)
        cout << -1 << " ";
      else
        cout << map[i][j] << " ";
    }
    cout << endl;
  }
}

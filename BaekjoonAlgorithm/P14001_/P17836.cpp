// ProblemNumber || ProblemName : P17836 - 공주님을 구해라!
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

int n, m, t;
int originalTime = 0;
int swordTime = 0;
int minTime;
int swordX, swordY;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int map[101][101];
int swordMap[101][101];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<int, pair<int, int>>> pq;

  cin >> n >> m >> t;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int state;
      cin >> state;
      if (state == 0)
      {
        map[i][j] = INF;
      }
      else if (state == 1)
      {
        map[i][j] = -1;
      }
      else
      {
        swordX = i;
        swordY = j;
        map[i][j] = INF;
      }
      swordMap[i][j] = INF;
    }
  }

  pq.push({0, {0, 0}});
  map[0][0] = 0;

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if (map[x][y] < cost)
      continue;

    for (int i = 0; i < 4; i++)
    {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if (moveX < 0 || moveY < 0 || moveX > n || moveY > m || map[moveX][moveY] <= map[x][y] + 1)
        continue;
      else
      {
        map[moveX][moveY] = map[x][y] + 1;
        pq.push({-map[moveX][moveY], {moveX, moveY}});
      }
    }
  }

  pq.push({0, {swordX, swordY}});
  swordMap[swordX][swordY] = 0;

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if (swordMap[x][y] < cost)
      continue;

    for (int i = 0; i < 4; i++)
    {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if (moveX < 0 || moveY < 0 || moveX > n || moveY > m || swordMap[moveX][moveY] <= swordMap[x][y] + 1)
        continue;
      else
      {
        swordMap[moveX][moveY] = swordMap[x][y] + 1;
        pq.push({-swordMap[moveX][moveY], {moveX, moveY}});
      }
    }
  }

  originalTime = map[n - 1][m - 1];
  swordTime = map[swordX][swordY] + swordMap[n - 1][m - 1];

  minTime = originalTime > swordTime ? swordTime : originalTime;

  if (minTime <= t)
  {
    cout << minTime << endl;
  }
  else
  {
    cout << "Fail" << endl;
  }
}

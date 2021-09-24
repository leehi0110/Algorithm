// ProblemNumber || ProblemName : P17141 - 연구소 2
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

int n, m;
int minTime = INF;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<bool> visit;
vector<pair<int, int>> virus;
vector<vector<int>> map(51, vector<int>(51, INF));

void DFS(int idx, int select);
void BFS();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int state;
      cin >> state;

      if (state == 1)
        map[i][j] = -1;
      else if (state == 2)
      {
        visit.push_back(false);
        virus.push_back({i, j});
      }
    }
  }

  DFS(0, 0);

  if (minTime == INF)
    cout << -1 << endl;
  else
    cout << minTime << endl;
}

void DFS(int idx, int select)
{
  if (select == m)
  {
    BFS();
    return;
  }

  for (int i = idx; i < visit.size(); i++)
  {
    if (visit[i])
      continue;
    visit[i] = true;

    DFS(i, select + 1);
    visit[i] = false;
  }
}

void BFS()
{
  vector<vector<int>> newMap = map;
  priority_queue<pair<int, pair<int, int>>> pq;

  for (int i = 0; i < visit.size(); i++)
  {
    if (visit[i])
    {
      int virusX = virus[i].first;
      int virusY = virus[i].second;

      newMap[virusX][virusY] = 0;
      pq.push({0, {virusX, virusY}});
    }
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int nowX = pq.top().second.first;
    int nowY = pq.top().second.second;

    pq.pop();

    for (int i = 0; i < 4; i++)
    {
      int moveX = nowX + dx[i];
      int moveY = nowY + dy[i];

      if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= n || newMap[moveX][moveY] <= cost + 1)
        continue;
      else
      {
        newMap[moveX][moveY] = cost + 1;
        pq.push({-newMap[moveX][moveY], {moveX, moveY}});
      }
    }
  }

  int needTime = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (newMap[i][j] > needTime)
        needTime = newMap[i][j];
    }
  }

  if (minTime > needTime)
    minTime = needTime;
}

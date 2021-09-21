// ProblemNumber || ProblemName : P11967 - 불 켜기
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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool light[101][101];
bool visit[101][101];
vector<vector<vector<pair<int, int>>>> graph(101, vector<vector<pair<int, int>>>(101));
priority_queue<pair<int, int>> pq;
// vector<pair<int, int>> pq;

void bfs();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> map(101, vector<int>(101, INF));
  int result = 0;

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      light[i][j] = false;
      visit[i][j] = false;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    graph[a][b].push_back({c, d});
  }

  light[1][1] = true;
  visit[1][1] = true;

  // pq.push({1, 1});
  pq.push({1, 1});

  // 불을 켠다
  // BFS를 통해 방문하지 않은 곳으로 간다
  // 새로 방문한 곳이 있을 경우, 그 방에서 켤 수 있는 방을 큐에 넣는다.

  while (!pq.empty())
  {
    int nowX = pq.top().first;
    int nowY = pq.top().second;

    pq.pop();

    for (int i = 0; i < graph[nowX][nowY].size(); i++)
    {
      light[graph[nowX][nowY][i].first][graph[nowX][nowY][i].second] = true;
    }

    if (pq.empty())
    {
      bfs();
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (light[i][j])
        result++;
    }
  }

  cout << result << endl;
}

void bfs()
{
  vector<vector<int>> map(n + 1, vector<int>(n + 1, INF));
  priority_queue<pair<int, pair<int, int>>> bfsQue;

  map[1][1] = 0;
  bfsQue.push({0, {1, 1}});

  while (!bfsQue.empty())
  {
    int cost = -bfsQue.top().first;
    int nowX = bfsQue.top().second.first;
    int nowY = bfsQue.top().second.second;

    bfsQue.pop();

    for (int i = 0; i < 4; i++)
    {
      int nextX = nowX + dx[i];
      int nextY = nowY + dy[i];

      if (nextX <= 0 || nextY <= 0 || nextX > n || nextY > n || map[nextX][nextY] <= cost + 1 || !light[nextX][nextY])
        continue;
      else
      {
        if (!visit[nextX][nextY])
        {
          visit[nextX][nextY] = true;
          pq.push({nextX, nextY});
        }

        map[nextX][nextY] = cost + 1;
        bfsQue.push({-map[nextX][nextY], {nextX, nextY}});
      }
    }
  }
}

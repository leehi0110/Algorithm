// ProblemNumber || ProblemName : P2589 - 보물섬
// 하면서 좀 더 깊게 생각하게 된 것들
// -> BFS는 우선순위큐를 이용해 푸는것이 효율적임
// -> 또한, 우선순위큐를 사용할 때 어떤 변수를 기준으로 사용할 지 신중하게 선택해야됨

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m;
string map[50][50];

int bfs(int x, int y, int dist);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int maxCnt = 0;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    string tmp;
    cin >> tmp;

    for (int j = 0; j < tmp.length(); j++)
    {
      map[i][j] = tmp.substr(j, 1);
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (map[i][j] == "L")
      {
        int bfsCnt = bfs(j, i, 0);

        if (bfsCnt > maxCnt)
          maxCnt = bfsCnt;
      }
    }
  }

  cout << maxCnt << endl;
}

int bfs(int x, int y, int dist)
{
  priority_queue<pair<int, pair<int, int>>> pq;
  vector<vector<int>> visit(n, vector<int>(m, INF));

  pq.push({0, {x, y}});
  visit[y][x] = 0;

  while (!pq.empty())
  {
    int nowDist = -pq.top().first;
    int nowX = pq.top().second.first;
    int nowY = pq.top().second.second;

    pq.pop();

    if (visit[nowY][nowX] < nowDist)
      continue;

    for (int i = 0; i < 4; i++)
    {
      int nextX = nowX + dx[i];
      int nextY = nowY + dy[i];

      if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n)
        continue;

      if (map[nextY][nextX] == "L" && visit[nextY][nextX] > nowDist + 1)
      {
        pq.push({-(nowDist + 1), {nextX, nextY}});
        visit[nextY][nextX] = nowDist + 1;
      }
    }
  }

  int maxCnt = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (visit[i][j] != INF && visit[i][j] > maxCnt)
      {
        maxCnt = visit[i][j];
      }
    }
  }

  return maxCnt;
}

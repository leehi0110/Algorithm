// ProblemNumber || ProblemName : P4179 - 불!
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 조건을 잘 읽고 문제를 명확하게 이해하자
// -> J(지훈)이는 하나만 들어오지만 F(불)은 여러개 들어올 수 있다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <queue>
#define INF 1e9

using namespace std;

int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int jihunMap[1001][1001];
int fireMap[1001][1001];

int jihunStart[2];
vector<pair<int, int>> fireStart;

int result = INF;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  priority_queue<pair<int, pair<int, int>>> pq;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    string temp;

    cin >> temp;

    for (int j = 0; j < temp.length(); j++)
    {
      if (temp[j] == '#')
      {
        jihunMap[i][j] = -1;
        fireMap[i][j] = -1;
      }
      else if (temp[j] == 'J')
      {
        jihunMap[i][j] = 1;
        jihunStart[0] = i;
        jihunStart[1] = j;
        fireMap[i][j] = INF;
      }
      else if (temp[j] == 'F')
      {
        fireMap[i][j] = 1;
        fireStart.push_back({i, j});
        // fireStart[0] = i;
        // fireStart[1] = j;
        jihunMap[i][j] = INF;
      }
      else
      {
        jihunMap[i][j] = INF;
        fireMap[i][j] = INF;
      }
    }
  }

  pq.push({-1, {jihunStart[0], jihunStart[1]}});

  while (!pq.empty())
  {
    int dist = -pq.top().first;
    int nowX = pq.top().second.first;
    int nowY = pq.top().second.second;

    pq.pop();

    for (int i = 0; i < 4; i++)
    {
      int nextX = nowX + dx[i];
      int nextY = nowY + dy[i];

      if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m || jihunMap[nextX][nextY] == -1 || jihunMap[nextX][nextY] <= dist + 1)
        continue;
      else
      {
        jihunMap[nextX][nextY] = dist + 1;
        pq.push({-jihunMap[nextX][nextY], {nextX, nextY}});
      }
    }
  }

  for (int i = 0; i < fireStart.size(); i++)
  {
    pq.push({-1, {fireStart[i].first, fireStart[i].second}});
  }

  while (!pq.empty())
  {
    int dist = -pq.top().first;
    int nowX = pq.top().second.first;
    int nowY = pq.top().second.second;

    pq.pop();

    for (int i = 0; i < 4; i++)
    {
      int nextX = nowX + dx[i];
      int nextY = nowY + dy[i];

      if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m || fireMap[nextX][nextY] == -1 || fireMap[nextX][nextY] <= dist + 1)
        continue;
      else
      {
        fireMap[nextX][nextY] = dist + 1;
        pq.push({-fireMap[nextX][nextY], {nextX, nextY}});
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
      {
        // cout << i << j << endl;
        if (jihunMap[i][j] < fireMap[i][j] && result > jihunMap[i][j])
        {
          result = jihunMap[i][j];
        }
      }
    }
  }

  if (result == INF)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << result << endl;
}

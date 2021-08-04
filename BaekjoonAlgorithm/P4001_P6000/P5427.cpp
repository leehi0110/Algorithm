// ProblemNumber || ProblemName : P5247 - 불
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

int testCase;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    solve();
  }
}

void solve()
{
  int n, m;
  int result = INF;

  cin >> m >> n;

  vector<vector<int>> userMap(n);
  vector<vector<int>> fireMap(n);
  pair<int, int> userSite = {0, 0};
  vector<pair<int, int>> fireState;
  priority_queue<pair<int, pair<int, int>>> pq;

  for (int i = 0; i < n; i++)
  {
    string mapRow;
    cin >> mapRow;

    for (int j = 0; j < mapRow.length(); j++)
    {
      char state = mapRow[j];

      if (state == '#')
      {
        userMap[i].push_back(-INF);
        fireMap[i].push_back(-INF);
      }
      else if (state == '.')
      {
        userMap[i].push_back(INF);
        fireMap[i].push_back(INF);
      }
      else if (state == '@')
      {
        fireMap[i].push_back(INF);
        userMap[i].push_back(1);

        userSite = {i, j};
      }
      else
      { // state = '*'
        userMap[i].push_back(INF);
        fireMap[i].push_back(1);

        fireState.push_back({i, j});
      }
    }
  }

  // userMapSet
  pq.push({-1, {userSite.first, userSite.second}});

  while (!pq.empty())
  {
    int time = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    for (int i = 0; i < 4; i++)
    {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= m || userMap[moveX][moveY] <= time + 1)
        continue;
      else
      {
        userMap[moveX][moveY] = time + 1;
        pq.push({-userMap[moveX][moveY], {moveX, moveY}});
      }
    }
  }

  for (int i = 0; i < fireState.size(); i++)
  {
    pq.push({-1, {fireState[i].first, fireState[i].second}});
  }

  while (!pq.empty())
  {
    int time = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    for (int i = 0; i < 4; i++)
    {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= m || fireMap[moveX][moveY] <= time + 1)
        continue;
      else
      {
        fireMap[moveX][moveY] = time + 1;
        pq.push({-fireMap[moveX][moveY], {moveX, moveY}});
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
      {
        if (userMap[i][j] < fireMap[i][j] && result > userMap[i][j])
          result = userMap[i][j];
      }
    }
  }

  if (result == INF)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << result << endl;
}

// ProblemNumber || ProblemName : P3055 - 탈출
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
int result = INF;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int>> water;
vector<vector<int>> waterMap(51, vector<int>(51, INF));
vector<vector<int>> sMap(51, vector<int>(51, INF));

pair<int, int> target_s;
pair<int, int> target_d;

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
      if (temp[j] == 'S')
      {
        target_s.first = i;
        target_s.second = j;
      }
      else if (temp[j] == '*')
      {
        water.push_back({i, j});
      }
      else if (temp[j] == 'D')
      {
        target_d.first = i;
        target_d.second = j;
        waterMap[i][j] = -1;
        sMap[i][j] = -1;
      }
      else if (temp[j] == 'X')
      {
        waterMap[i][j] = -1;
        sMap[i][j] = -1;
      }
    }
  }

  for (int i = 0; i < water.size(); i++)
  {
    pq.push({0, {water[i].first, water[i].second}});
    waterMap[water[i].first][water[i].second] = 0;
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    for (int i = 0; i < 4; i++)
    {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= m || waterMap[moveX][moveY] <= cost + 1)
        continue;
      else
      {
        waterMap[moveX][moveY] = cost + 1;
        pq.push({-(cost + 1), {moveX, moveY}});
      }
    }
  }

  pq.push({0, {target_s.first, target_s.second}});
  sMap[target_s.first][target_s.second] = 0;

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    for (int i = 0; i < 4; i++)
    {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= m || sMap[moveX][moveY] <= cost + 1)
        continue;
      else
      {
        sMap[moveX][moveY] = cost + 1;
        pq.push({-(cost + 1), {moveX, moveY}});
      }
    }
  }

  for (int i = 0; i < 4; i++)
  {
    int moveX = target_d.first + dx[i];
    int moveY = target_d.second + dy[i];

    if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= m || sMap[moveX][moveY] == -1)
      continue;
    else
    {
      if (waterMap[moveX][moveY] > sMap[moveX][moveY] && sMap[moveX][moveY] < result)
      {
        result = sMap[moveX][moveY];
      }
    }
  }

  if (result == INF)
    cout << "KAKTUS" << endl;
  else
    cout << result + 1 << endl;
}

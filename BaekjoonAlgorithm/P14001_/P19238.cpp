// ProblemNumber || ProblemName : P19238 - 스타트 택시
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

int n, m, gas;
bool flag = false;
int taxi_x, taxi_y;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[21][21];
vector<pair<pair<int, int>, pair<int, int>>> customer;
// customer[i] = i 고객의 시작 좌표 , i 고객의 도착 좌표

vector<vector<int>> BFS(int x, int y);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> gas;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> map[i][j];
    }
  }

  cin >> taxi_x >> taxi_y;

  for (int i = 0; i < m; i++)
  {
    int start_x, start_y, end_x, end_y;

    cin >> start_x >> start_y >> end_x >> end_y;

    customer.push_back({{start_x, start_y}, {end_x, end_y}});
    // 고객의 출발좌표, 도착좌표
  }

  sort(customer.begin(), customer.end());
  // 고객의 행과 열을 기준으로 정렬

  while (!customer.empty())
  {

    int minPickUp = INF;
    int minIdx = INF;

    vector<vector<int>> taxiDist = BFS(taxi_x, taxi_y);
    // 현재 택시에서 갈 수 있는 최단거리

    for (int i = 0; i < customer.size(); i++)
    {
      int x = customer[i].first.first;
      int y = customer[i].first.second;

      if (taxiDist[x][y] < minPickUp)
      {
        minPickUp = taxiDist[x][y];
        minIdx = i;
      }
    } // 데리러 갈 수 있는 최단 거리

    if (minPickUp == INF)
    {
      flag = true;
      break;
    }
    else if (gas <= minPickUp)
    {
      flag = true;
      break;
    }
    else
    {
      gas -= minPickUp;
    }

    taxiDist = BFS(customer[minIdx].first.first, customer[minIdx].first.second);

    int driveDist = taxiDist[customer[minIdx].second.first][customer[minIdx].second.second];

    if (driveDist == INF || gas < driveDist)
    {
      flag = true;
      break;
    }
    else
    {
      gas += driveDist;
      taxi_x = customer[minIdx].second.first;
      taxi_y = customer[minIdx].second.second;
      customer.erase(customer.begin() + minIdx, customer.begin() + minIdx + 1);
    }
  }

  if (flag)
    cout << "-1" << endl;
  else
    cout << gas << endl;
}

vector<vector<int>> BFS(int x, int y)
{
  priority_queue<pair<int, pair<int, int>>> pq;
  vector<vector<int>> distMap(n + 1, vector<int>(n + 1, INF));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (map[i][j] == 1)
        distMap[i][j] = -1;
    }
  }

  distMap[x][y] = 0;
  pq.push({0, {x, y}});

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

      if (moveX < 1 || moveY < 1 || moveX > n || moveY > n || distMap[moveX][moveY] <= cost + 1)
        continue;
      else
      {
        distMap[moveX][moveY] = cost + 1;
        pq.push({-distMap[moveX][moveY], {moveX, moveY}});
      }
    }
  }

  return distMap;
}

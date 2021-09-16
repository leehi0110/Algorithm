// ProblemNumber || ProblemName : P7562 - 나이트의 이동
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

int n;
int startX, startY, endX, endY;
int map[301][301];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void solution();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;
  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    solution();
  }
}

void solution()
{
  priority_queue<pair<int, pair<int, int>>> pq;

  cin >> n;
  cin >> startX >> startY;
  cin >> endX >> endY;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      map[i][j] = INF;
    }
  }

  map[startX][startY] = 0;
  pq.push({0, {startX, startY}});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int nowX = pq.top().second.first;
    int nowY = pq.top().second.second;

    pq.pop();

    for (int i = 0; i < 8; i++)
    {
      int moveX = nowX + dx[i];
      int moveY = nowY + dy[i];

      if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= n || map[moveX][moveY] <= cost + 1)
        continue;
      else
      {
        map[moveX][moveY] = cost + 1;
        pq.push({-map[moveX][moveY], {moveX, moveY}});
      }
    }
  }

  cout << map[endX][endY] << endl;
}

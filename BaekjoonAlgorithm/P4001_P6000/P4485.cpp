// ProblemNumber || ProblemName : P4485 - 녹색 옷 입은 애가 젤다지?
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 비용이 많거나 같은 경우는 모두 큐에 포함하지 않도록 하여 메모리를 최대한 절약한다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9

using namespace std;

int table[126][126];
int rupee[126][126];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int problemNum = 0;

void Dijkstra(int n);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  while (1)
  {
    int n;
    problemNum++;

    cin >> n;

    if (n == 0)
      break;
    Dijkstra(n);
  }
}

void Dijkstra(int n)
{
  priority_queue<pair<int, pair<int, int>>> pq;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> rupee[i][j];
      table[i][j] = INF;
    }
  }

  table[0][0] = rupee[0][0];
  pq.push({-rupee[0][0], {0, 0}});

  while (!pq.empty())
  {
    if (table[n - 1][n - 1] != INF)
      break;

    int cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if (table[x][y] < cost)
      continue;

    for (int i = 0; i < 4; i++)
    {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= n || table[moveX][moveY] <= cost + rupee[moveX][moveY])
        continue;
      else
      {
        table[moveX][moveY] = cost + rupee[moveX][moveY];
        pq.push({-(cost + rupee[moveX][moveY]), {moveX, moveY}});
      }
    }
  }

  cout << "Problem " << problemNum << ": " << table[n - 1][n - 1] << "\n";
}

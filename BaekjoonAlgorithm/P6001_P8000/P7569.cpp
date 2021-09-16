// ProblemNumber || ProblemName : P7569 - 토마토
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

int n, m, h;
int result = 0;
int box[101][101][101];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<int, vector<int>>> pq;

  cin >> m >> n >> h;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        int state;

        cin >> state;
        if (state == -1)
          box[i][j][k] = -1;
        else if (state == 1)
        {
          box[i][j][k] = 0;
          pq.push({0, {i, j, k}});
        }
        else
        {
          box[i][j][k] = INF;
        }
      }
    }
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int nowZ = pq.top().second[0];
    int nowX = pq.top().second[1];
    int nowY = pq.top().second[2];

    pq.pop();

    for (int i = 0; i < 6; i++)
    {
      int moveZ = nowZ + dz[i];
      int moveX = nowX + dx[i];
      int moveY = nowY + dy[i];

      if (moveZ < 0 || moveX < 0 || moveY < 0 || moveZ >= h || moveX >= n || moveY >= m || box[moveZ][moveX][moveY] == -1 || box[moveZ][moveX][moveY] <= cost + 1)
        continue;
      else
      {
        box[moveZ][moveX][moveY] = cost + 1;
        pq.push({-(cost + 1), {moveZ, moveX, moveY}});
      }
    }
  }

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        if (box[i][j][k] > result)
        {
          result = box[i][j][k];
        }
      }
    }
  }

  if (result == INF)
    cout << "-1" << endl;
  else
    cout << result << endl;
}

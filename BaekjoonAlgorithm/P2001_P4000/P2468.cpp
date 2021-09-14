// ProblemNumber || ProblemName : P2468 - 안전 영역
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n;
int result = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(vector<vector<int>> map, int height);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  vector<vector<int>> map(n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int height;

      cin >> height;

      map[i].push_back(height);
    }
  }

  for (int i = 0; i < 101; i++)
  {
    int returnVal = bfs(map, i);

    if (returnVal > result)
      result = returnVal;
    else if (returnVal == 0)
      break;
  }

  cout << result << endl;
}

int bfs(vector<vector<int>> map, int height)
{
  int count = 0;
  queue<pair<int, int>> que;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {

      if (map[i][j] > height)
      {
        count--;

        map[i][j] = count;
        que.push({i, j});
      }

      while (!que.empty())
      {
        int x = que.front().first;
        int y = que.front().second;

        que.pop();

        for (int k = 0; k < 4; k++)
        {
          int moveX = x + dx[k];
          int moveY = y + dy[k];

          if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= n || map[moveX][moveY] < 0 || map[moveX][moveY] <= height)
            continue;
          else
          {
            map[moveX][moveY] = count;
            que.push({moveX, moveY});
          }
        }
      }
    }
  }

  return count * -1;
}

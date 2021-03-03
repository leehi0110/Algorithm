// ProblemNumber || ProblemName : 게임 개발

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
  int N, M;
  int x, y, direction;
  int cnt = 0;
  bool flag = true;

  vector<pair<int, int>> dir = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
  vector<vector<int>> arr;

  cin >> N >> M;
  cin >> x >> y >> direction;

  for (int i = 0; i < N; i++)
  {
    vector<int> temp;
    for (int j = 0; j < M; j++)
    {
      int state;
      cin >> state;
      temp.push_back(state);
    }
    arr.push_back(temp);
  }

  arr[x][y] = 2;

  while (flag)
  {
    for (int i = 0; i < 4; i++)
    {
      direction = (direction + 3) % 4;
      int nextX = x + dir[direction].first;
      int nextY = y + dir[direction].second;

      if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
        continue;

      if (arr[nextX][nextY] == 0)
      {
        arr[nextX][nextY] = 2;
        x = nextX;
        y = nextY;
        cnt++;
        break;
      }

      if (i == 3)
      {
        int nextDirection = (direction + 2) % 4;
        nextX = x + dir[nextDirection].first;
        nextY = y + dir[nextDirection].second;

        if (arr[nextX][nextY] == 1)
        {
          flag = !flag;
          break;
        }
        else
        {
          x = nextX;
          y = nextY;
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
}

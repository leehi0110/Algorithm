// ProblemNumber || ProblemName : P2665 - 미로 만들기
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
char map[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<int>> table(51, vector<int>(51, INF));

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<int, pair<int, int>>> pq;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;

    for (int j = 0; j < str.length(); j++)
    {
      if (str[j] == '1')
        map[i][j] = 'W';
      else
        map[i][j] = 'B';
    }
  }

  if (map[0][0] == 'W')
    table[0][0] = 0;
  else
    table[0][0] = 1;

  pq.push({0, {0, 0}});

  while (!pq.empty())
  {
    int changeDoor = -pq.top().first;
    int nowX = pq.top().second.first;
    int nowY = pq.top().second.second;

    pq.pop();

    for (int i = 0; i < 4; i++)
    {
      int moveX = nowX + dx[i];
      int moveY = nowY + dy[i];

      if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= n)
        continue;

      if (map[moveX][moveY] == 'W')
      {
        if (table[moveX][moveY] <= changeDoor)
          continue;
        else
        {
          table[moveX][moveY] = changeDoor;
          pq.push({-changeDoor, {moveX, moveY}});
        }
      }
      else
      {
        if (table[moveX][moveY] <= changeDoor + 1)
          continue;
        else
        {
          table[moveX][moveY] = changeDoor + 1;
          pq.push({-table[moveX][moveY], {moveX, moveY}});
        }
      }
    }
  }

  cout << table[n - 1][n - 1] << endl;
}

// ProblemNumber || ProblemName : P14502 - 연구소
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int maxCnt = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int>> well;

void getSafeArea(vector<vector<int>> map);
void checkWell(int idx, int selected, vector<vector<int>> map);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  vector<vector<int>> map(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      if (map[i][j] == 0)
        well.push_back({i, j});
    }
  }

  checkWell(0, 0, map);

  cout << maxCnt << endl;
}

void checkWell(int idx, int selected, vector<vector<int>> map)
{
  if (selected == 3)
  {
    getSafeArea(map);
    return;
  }

  if (idx == well.size())
    return;

  map[well[idx].first][well[idx].second] = 1;
  checkWell(idx + 1, selected + 1, map);

  map[well[idx].first][well[idx].second] = 0;
  checkWell(idx + 1, selected, map);
}

void getSafeArea(vector<vector<int>> map)
{

  priority_queue<pair<int, int>> pq;
  int safeAreaCnt = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (map[i][j] == 2)
      {
        pq.push({i, j});
      }

      while (!pq.empty())
      {
        int x = pq.top().first;
        int y = pq.top().second;

        pq.pop();

        for (int k = 0; k < 4; k++)
        {
          int moveX = x + dx[k];
          int moveY = y + dy[k];

          if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= m || map[moveX][moveY] != 0)
            continue;
          else
          {
            map[moveX][moveY] = 2;
            pq.push({moveX, moveY});
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (map[i][j] == 0)
      {
        safeAreaCnt++;
      }
    }
  }

  if (maxCnt < safeAreaCnt)
  {
    maxCnt = safeAreaCnt;
  }
}

// ProblemNumber || ProblemName : P7576 - 토마토

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <utility>

using namespace std;
int n, m;

void BFS(vector<vector<int>> &box, deque<pair<int, int>> &reapXY, int nextX, int nextY, int maxDay, int &reapCnt);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int reapCnt = 0;
  int unReapCnt = 0;
  int emptyCnt = 0;

  cin >> m >> n;

  vector<vector<int>> box(n, vector<int>(m, 0));
  // vector<pair<int, int>> reapXY;
  deque<pair<int, int>> reapXY;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> box[i][j];
      if (box[i][j] == 1)
      {
        reapCnt++;
        // reapXY.push_back(pair<int, int>(i, j));
        reapXY.push_back(pair<int, int>(i, j));
      }
      else if (box[i][j] == 0)
        unReapCnt++;
      else
        emptyCnt++;
    }
  }

  if (reapCnt == 0)
    cout << -1 << endl; // 모든 토마토가 익을 수 없는 상태
  else if (reapCnt + emptyCnt == n * m)
    cout << 0 << endl; // 모든 토마토가 익어있는 상태
  else                 // 토마토가 모두 익기 위해 걸리는 시간을 계산하는 로직 필요
  {

    while (!reapXY.empty())
    {
      int nowX = reapXY.front().first;
      int nowY = reapXY.front().second;

      reapXY.pop_front();

      BFS(box, reapXY, nowX + 1, nowY, box[nowX][nowY] + 1, reapCnt);
      BFS(box, reapXY, nowX - 1, nowY, box[nowX][nowY] + 1, reapCnt);
      BFS(box, reapXY, nowX, nowY + 1, box[nowX][nowY] + 1, reapCnt);
      BFS(box, reapXY, nowX, nowY - 1, box[nowX][nowY] + 1, reapCnt);
    }

    int maxDay = 0;

    for (int i = 0; i < box.size(); i++)
    {
      for (int j = 0; j < box[i].size(); j++)
      {
        if (box[i][j] == 0)
        {
          cout << -1 << endl;
          return 0;
        }
        else if (box[i][j] > maxDay)
        {
          maxDay = box[i][j];
        }
      }
    }
    cout << maxDay - 1 << endl;
  }
}

void BFS(vector<vector<int>> &box, deque<pair<int, int>> &reapXY, int nextX, int nextY, int maxDay, int &reapCnt)
{
  if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || box[nextX][nextY] == -1 || box[nextX][nextY] == 1)
    return;
  else if (box[nextX][nextY] == 0)
  {
    box[nextX][nextY] = maxDay;
    reapXY.push_back(pair<int, int>(nextX, nextY));
    reapCnt--;
  }
  else
  {
    if (box[nextX][nextY] > maxDay)
    {
      box[nextX][nextY] = maxDay;
      reapXY.push_back(pair<int, int>(nextX, nextY));
    }
  }
}
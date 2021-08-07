// ProblemNumber || ProblemName : P1937 - 욕심쟁이 판다
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
int maxDist = 0;
long long tree[501][501];
vector<vector<int>> dp(501, vector<int>(501, 0));
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> tree[i][j];
    }
  } // 대나무의 개수 입력

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      DFS(i, j);
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (maxDist < dp[i][j])
        maxDist = dp[i][j];
    }
  }

  cout << maxDist << endl;
}

void DFS(int x, int y)
{
  if (dp[x][y] == 0)
  {
    int dist = 0;

    for (int i = 0; i < 4; i++)
    {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if (moveX < 0 || moveY < 0 || moveX >= n || moveY >= n || tree[x][y] >= tree[moveX][moveY])
        continue;

      DFS(moveX, moveY);

      if (dist < dp[moveX][moveY])
        dist = dp[moveX][moveY];
    }

    dp[x][y] = dist + 1;
  }
}

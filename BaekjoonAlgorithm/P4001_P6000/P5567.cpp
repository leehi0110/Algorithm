// ProblemNumber || ProblemName : P5567 - 결혼식
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

int friends[501][501];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int result = 0;

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        friends[i][j] = 0;
      else
        friends[i][j] = INF;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;

    cin >> a >> b;

    friends[a][b] = 1;
    friends[b][a] = 1;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);
      }
    }
  }

  for (int i = 2; i <= n; i++)
  {
    if (friends[1][i] < 3)
      result++;
  }

  cout << result << endl;
}

// ProblemNumber || ProblemName : P2458 - 키 순서
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int table[501][501];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int result = 0;

  cin >> n >> m;
  vector<int> path(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        table[i][j] = 1;
      else
        table[i][j] = INF;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int small, big;

    cin >> small >> big;

    table[small][big] = 1;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i != j && table[i][j] != INF)
      {
        path[i]++;
        path[j]++;

        if (path[i] == n - 1)
          result++;
        if (path[j] == n - 1)
          result++;
      }
    }
  }

  cout << result << endl;
}

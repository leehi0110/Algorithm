// ProblemNumber || ProblemName : P1389 - 케빈 베이컨의 6단계 법칙
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;
int table[101][101] = {0};

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int minCnt = INF;
  int result;

  cin >> n >> m;

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
    int a, b;

    cin >> a >> b;

    table[a][b] = 1;
    table[b][a] = 1;
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
    int cnt = 0;
    for (int j = 1; j <= n; j++)
    {
      cnt += table[i][j];
    }

    if (minCnt > cnt)
    {
      minCnt = cnt;
      result = i;
    }
  }

  cout << result << endl;
}
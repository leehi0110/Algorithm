// ProblemNumber || ProblemName : P14938 - 서강그라운드
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, r;
  int maxItem = 0;

  cin >> n >> m >> r;

  vector<int> item(n + 1);
  vector<vector<int>> map(n + 1, vector<int>(n + 1, INF));

  for (int i = 1; i <= n; i++)
  {
    map[i][i] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    cin >> item[i + 1];
  }

  for (int i = 0; i < r; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    map[a][b] = c;
    map[b][a] = c;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    int cnt = 0;
    for (int j = 1; j <= n; j++)
    {
      if (map[i][j] <= m)
        cnt += item[j];
    }
    if (maxItem < cnt)
      maxItem = cnt;
  }

  cout << maxItem << endl;
}

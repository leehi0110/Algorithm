// ProblemNumber || ProblemName : P1719 - 택배
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define INF 1e9

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
  vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    dist[i][i] = 0;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;
    dist[a][b] = c;
    dist[b][a] = c;

    table[a][b] = b;
    table[b][a] = a;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (dist[i][j] > dist[i][k] + dist[k][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];

          if (table[i][k] != k)
          {
            table[i][j] = table[i][k];
          }
          else
          {
            table[i][j] = k;
          }
        }
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (table[i][j] == 0)
      {
        cout << "- ";
      }
      else
        cout << table[i][j] << " ";
    }
    cout << endl;
  }
}

// ProblemNumber || ProblemName : P11404 - 플로이드

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

  int n, m;

  cin >> n;
  cin >> m;

  vector<vector<int>> table(n, vector<int>(n, INF));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        table[i][j] = 0;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int start, end, cost;

    cin >> start >> end >> cost;

    if (table[start - 1][end - 1] > cost)
    {
      table[start - 1][end - 1] = cost;
    }
  }

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (table[i][j] == INF)
      {
        cout << 0 << " ";
      }
      else
        cout << table[i][j] << " ";
    }
    cout << endl;
  }
}

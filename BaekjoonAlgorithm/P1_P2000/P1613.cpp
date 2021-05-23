// ProblemNumber || ProblemName : P1613 - 역사

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 1e9

using namespace std;

int table[401][401];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;

  cin >> n >> k;

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == j)
        table[i][j] = 0;
      else
        table[i][j] = INF;
    }
  }

  for (int i = 0; i < k; i++)
  {
    int prev, next;

    cin >> prev >> next;

    table[prev][next] = 1;
  }

  for (int k = 0; k <= n; k++)
  {
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
      }
    }
  }

  int s;

  cin >> s;

  for (int i = 0; i < s; i++)
  {
    int prev, next;
    cin >> prev >> next;

    if (table[prev][next] >= INF)
    {
      if (table[next][prev] >= INF)
        cout << "0\n";
      else
        cout << "1\n";
    }
    else
      cout << "-1\n";
  }
}

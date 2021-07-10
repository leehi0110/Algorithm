// ProblemNumber || ProblemName : P1956 - 운동
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int table[401][401];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int v, e;
  int minDist = INF;

  cin >> v >> e;

  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      if (i != j)
        table[i][j] = INF;
      else
        table[i][j] = 0;
    }
  }

  for (int i = 0; i < e; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    table[a][b] = c;
  }

  for (int k = 1; k <= v; k++)
  {
    for (int i = 1; i <= v; i++)
    {
      for (int j = 1; j <= v; j++)
      {
        table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
      }
    }
  }

  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      if (i != j && table[i][j] != INF && table[j][i] != INF && table[i][j] + table[j][i] < minDist)
      {
        minDist = table[i][j] + table[j][i];
      }
    }
  }

  if (minDist != INF)
  {
    cout << minDist << endl;
  }
  else
    cout << "-1" << endl;
}

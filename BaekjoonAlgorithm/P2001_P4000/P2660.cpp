// ProblemNumber || ProblemName : P2660 - 회장 뽑기
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

int n;
int table[51][51];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> result;
  int minPoint = INF;

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        table[i][j] = 0;
      else
        table[i][j] = INF;
    }
  }

  while (1)
  {
    int a, b;

    cin >> a >> b;

    if (a == -1 && b == -1)
      break;
    else
    {
      table[a][b] = 1;
      table[b][a] = 1;
    }
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
    int maxPoint = -1;
    for (int j = 1; j <= n; j++)
    {
      if (table[i][j] > maxPoint)
        maxPoint = table[i][j];
    }

    if (maxPoint < minPoint)
    {
      result.clear();
      result.push_back(i);
      minPoint = maxPoint;
    }
    else if (maxPoint == minPoint)
    {
      result.push_back(i);
    }
  }

  sort(result.begin(), result.end());

  cout << minPoint << " " << result.size() << endl;
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;
}

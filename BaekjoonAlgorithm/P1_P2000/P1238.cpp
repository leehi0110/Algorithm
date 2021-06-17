// ProblemNumber || ProblemName : P1238 - 파티
// 하면서 좀 더 깊게 생각하게 된 것들
// -> n <= 1000 일 경우 플로이드와샬을 이용해 풀면 시간 초과가 날 수 있다.
// -> 만약, 조건을 이용해 반복문의 횟수를 줄일 수 있다면 이렇게 푸는 것이 더 편리하다
// -> 그렇지 않으면 다익스트라 알고리즘을 이용해 푼다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int table[1001][1001];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, x;
  int maxResult = 0;

  cin >> n >> m >> x;

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

  for (int i = 0; i < m; i++)
  {
    int start, end, cost;

    cin >> start >> end >> cost;

    table[start][end] = cost;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      if (table[i][k] != INF)
      {
        for (int j = 1; j <= n; j++)
        {
          table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
        }
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (table[i][x] + table[x][i] > maxResult)
      maxResult = table[i][x] + table[x][i];
  }

  cout << maxResult << endl;
}
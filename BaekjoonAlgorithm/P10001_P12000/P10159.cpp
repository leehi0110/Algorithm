// ProblemNumber || ProblemName : P10159 - 저울
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 플로이드와샬 알고리즘은 중간에 다른 정점을 거쳐 목표로 하는 정점에 도달할 수 있는지 확인하는 알고리즘이다
// -> 따라서, a와 b의 대소관계를 a정점에서 b정점으로 갈 수 있다고 바꿔 생각하여 c와 직접 비교하지 않아도 대소를 알 수 있는지 확인한다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int table[101][101];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n;
  cin >> m;

  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < n + 1; j++)
    {
      if (i == j)
        table[i][j] = 1;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;

    cin >> a >> b;

    table[a][b] = 1;
  }

  // a가 b보다 무겁다
  // b보다 가벼운 것들은 a보다 가볍다

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (table[i][k] == 1 && table[k][j] == 1)
        {
          table[i][j] = 1;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (table[i][j] == 1)
        table[j][i] = 1;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    int cnt = 0;
    for (int j = 1; j <= n; j++)
    {
      if (table[i][j] == 0)
        cnt++;
    }
    cout << cnt << endl;
  }
}
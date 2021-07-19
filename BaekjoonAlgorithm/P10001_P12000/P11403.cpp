// ProblemNumber || ProblemName : P11403 - 경로 찾기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

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

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> table[i][j];
    }
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (table[i][k] == 1 && table[k][j] == 1)
          table[i][j] = 1;
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << table[i][j] << " ";
    }
    cout << endl;
  }
}

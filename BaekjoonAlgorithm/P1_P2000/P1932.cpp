// ProblemNumber || ProblemName : P1932 - 정수 삼각형

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> table(n, vector<int>(n, 0));
  vector<vector<int>> vec(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      int temp;
      cin >> temp;
      vec[i][j] = temp;
    }
  }

  table[0][0] = vec[0][0];

  for (int i = 1; i < n; i++)
  {

    for (int j = 0; j < i + 1; j++)
    {
      if (j == 0)
      {
        table[i][j] = vec[i][j] + table[i - 1][j];
      }
      else if (j == i)
      {
        table[i][j] = vec[i][j] + table[i - 1][j - 1];
      }
      else
      {
        table[i][j] = max(table[i - 1][j - 1], table[i - 1][j]) + vec[i][j];
      }
    }
  }

  cout << *max_element(table[n - 1].begin(), table[n - 1].end()) << endl;
}

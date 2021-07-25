// ProblemNumber || ProblemName : P13424 - 비밀 모임
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int testCase;
int n, m, k;
void Floyd();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    Floyd();
  }
}

void Floyd()
{
  cin >> n >> m;

  vector<vector<int>> table(n + 1, vector<int>(n + 1, INF));
  vector<int> site;

  for (int i = 1; i <= n; i++)
  {
    table[i][i] = 0;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    table[a][b] = c;
    table[b][a] = c;
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
  } // FloydWarshall

  cin >> k;

  for (int i = 0; i < k; i++)
  {
    int temp;
    cin >> temp;

    site.push_back(temp);
  }

  int minDist = INF;
  int minRoomNumber;

  for (int i = 1; i <= n; i++)
  {
    int dist = 0;

    for (int j = 0; j < site.size(); j++)
    {
      dist += table[site[j]][i];
    }

    if (minDist > dist)
    {
      minDist = dist;
      minRoomNumber = i;
    }
  }

  cout << minRoomNumber << endl;
}

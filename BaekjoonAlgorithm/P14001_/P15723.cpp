// ProblemNumber || ProblemName : P15723 - n단 논법
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

int n, m;
vector<vector<int>> map(27, vector<int>(27, INF));

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  cin.ignore();

  for (int i = 0; i < 27; i++)
  {
    map[i][i] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    string temp;
    char before, after;

    getline(cin, temp);

    before = temp[0];
    after = temp[temp.length() - 1];

    map[before - 'a'][after - 'a'] = 1;
  }

  for (int k = 0; k < 27; k++)
  {
    for (int i = 0; i < 27; i++)
    {
      for (int j = 0; j < 27; j++)
      {
        map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
      }
    }
  }

  cin >> m;
  cin.ignore();

  for (int i = 0; i < m; i++)
  {
    string temp;
    char before, after;
    getline(cin, temp);

    before = temp[0];
    after = temp[temp.length() - 1];

    if (map[before - 'a'][after - 'a'] != INF)
      cout << "T" << endl;
    else
      cout << "F" << endl;
  }
}

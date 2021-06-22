// ProblemNumber || ProblemName : P10026 - 적록색약
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

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

  vector<vector<char>> map(n);

  for (int i = 0; i < n; i++)
  {
    string temp;

    cin >> temp;
    for (int j = 0; j < temp.length(); j++)
    {
      map[i].push_back(temp[j]);
    }
  }

  for (int i = 0; i < map.size(); i++)
  {
    for (int j = 0; j < map.size(); j++)
    {
      cout << map[i][j] << " ";
    }
    cout << endl;
  }
}

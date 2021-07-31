// ProblemNumber || ProblemName : P4179 - 불!
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char map[1001][1001];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    string temp;

    cin >> temp;

    for (int j = 0; j < temp.length(); j++)
    {
      map[i][j] = temp[j];
    }
  }
}

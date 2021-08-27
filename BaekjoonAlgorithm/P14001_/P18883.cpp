// ProblemNumber || ProblemName : P18883 - N M 찍기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int num = 1;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << num;
      if (j != m - 1)
        cout << " ";
      num++;
    }
    cout << endl;
  }
}

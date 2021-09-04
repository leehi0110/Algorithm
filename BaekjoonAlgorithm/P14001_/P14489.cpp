// ProblemNumber || ProblemName : P14489 - 치킨 두 마리
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

  int a, b, c;

  cin >> a >> b >> c;

  if (a + b >= 2 * c)
    cout << a + b - (2 * c) << endl;
  else
    cout << a + b << endl;
}

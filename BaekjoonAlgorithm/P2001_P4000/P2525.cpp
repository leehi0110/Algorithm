// ProblemNumber || ProblemName : P2525 - 오븐 시계
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

  int h, m, n;

  cin >> h >> m;
  cin >> n;

  m += n;
  h += (m / 60);
  m %= 60;
  h %= 24;

  cout << h << " " << m << endl;
}

// ProblemNumber || ProblemName : P10824 - 네 수
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

  int a, b, c, d;
  long long result = 0;

  cin >> a >> b >> c >> d;

  result = (stoll(to_string(a) + to_string(b)) + stoll(to_string(c) + to_string(d)));

  cout << result << endl;
}

// ProblemNumber || ProblemName : P16916 - 부분 문자열
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  string p, s;

  cin >> s;
  cin >> p;

  if (strstr((char *)s.c_str(), (char *)p.c_str()) == NULL)
    cout << 0 << endl;
  else
    cout << 1 << endl;
}

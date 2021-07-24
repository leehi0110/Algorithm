// ProblemNumber || ProblemName : P2748 - 피보나치 수 2
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long table[91];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  table[0] = 0;
  table[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    table[i] = table[i - 1] + table[i - 2];
  }

  cout << table[n] << endl;
}

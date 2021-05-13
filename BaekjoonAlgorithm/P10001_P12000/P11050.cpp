// ProblemNumber || ProblemName : P11050 - 이항 계수 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;

  cin >> n >> k;
  vector<int> table(n + 1, 1);

  for (int i = 1; i <= n; i++)
  {
    table[i] = table[i - 1] * i;
  }
  cout << table[n] / (table[n - k] * table[k]) << endl;
}

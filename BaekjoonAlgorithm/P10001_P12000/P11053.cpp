// ProblemNumber || ProblemName : P11053 - 가장 긴 증가하는 부분수열
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  vector<int> vec(n + 1, 0);
  vector<int> table(1001, 0);

  for (int i = 1; i <= n; i++)
  {
    cin >> vec[i];
  }

  for (int i = 1; i <= n; i++)
  {
    int now = vec[i];
    int maxEle = *max_element(table.begin(), table.begin() + now);
    table[now] = maxEle + 1;
  }

  cout << *max_element(table.begin(), table.end()) << endl;
}
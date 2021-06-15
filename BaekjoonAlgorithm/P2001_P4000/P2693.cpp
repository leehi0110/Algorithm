// ProblemNumber || ProblemName : P2693 - N번째 큰 수
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    multiset<int> set;

    for (int i = 0; i < 10; i++)
    {
      int num;
      cin >> num;

      set.insert(-num);
    }
    auto it = set.begin();
    for (int i = 0; i < 2; i++)
    {
      it++;
    }

    cout << -1 * (*it) << endl;
  }
}

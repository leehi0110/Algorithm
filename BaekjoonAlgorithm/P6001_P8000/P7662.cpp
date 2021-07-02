// ProblemNumber || ProblemName : P7662 - 이중 우선순위 큐
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
    int n;
    multiset<int> set;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
      char cmd;
      int num;

      cin >> cmd;
      cin >> num;

      if (cmd == 'I')
      { // insert
        set.insert(num);
      }
      else
      { // delete
        if (!set.empty())
        {
          if (num == 1)
          { // 최댓값 삭제
            auto it = set.end();
            it--;
            set.erase(it);
          }
          else
          { // 최솟값 삭제
            set.erase(set.begin());
          }
        }
      }
    }

    if (set.empty())
      cout << "EMPTY" << endl;
    else
      cout << *set.rbegin() << " " << *set.begin() << endl;
  }
}
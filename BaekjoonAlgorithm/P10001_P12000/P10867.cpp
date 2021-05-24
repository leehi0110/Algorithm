// ProblemNumber || ProblemName : P10867 - 중복빼고 정렬하기

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

  int n;
  set<int> set;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;

    set.insert(temp);
  }

  for (auto it = set.begin(); it != set.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}

// ProblemNumber || ProblemName : P1453 - 피시방 알바
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

  int n;
  int result = 0;
  vector<int> seat;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;

    if (find(seat.begin(), seat.end(), num) == seat.end())
    {
      seat.push_back(num);
    }
    else
      result++;
  }

  cout << result << endl;
}

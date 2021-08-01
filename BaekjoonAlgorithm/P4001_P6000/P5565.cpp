// ProblemNumber || ProblemName : P5565 - 영수증
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

  int sum;

  cin >> sum;

  for (int i = 0; i < 9; i++)
  {
    int price;
    cin >> price;
    sum -= price;
  }

  cout << sum << endl;
}

// ProblemNumber || ProblemName : P2576 - 홀수
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

  int sum = 0;
  int minOdd = 1e9;

  for (int i = 0; i < 7; i++)
  {
    int temp;
    cin >> temp;

    if (temp % 2 != 0)
    {
      sum += temp;

      if (minOdd > temp)
        minOdd = temp;
    }
  }

  if (sum == 0)
    cout << -1 << endl;
  else
  {
    cout << sum << endl;
    cout << minOdd << endl;
  }
}

// ProblemNumber || ProblemName : P10797 - 10부제
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

  int num;
  int result = 0;

  cin >> num;

  for (int i = 0; i < 5; i++)
  {
    int temp;

    cin >> temp;

    if (temp == num)
      result++;
  }

  cout << result << endl;
}

// ProblemNumber || ProblemName : P2455 - 지능형 기차
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

  int max = 0;
  int person = 0;

  for (int i = 0; i < 4; i++)
  {
    int off, on;

    cin >> off >> on;

    person -= off;
    person += on;

    if (max <= person)
      max = person;
  }

  cout << max << endl;
}

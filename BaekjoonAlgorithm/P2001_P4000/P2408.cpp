// ProblemNumber || ProblemName : P2408 - 주사위 세개
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

  vector<int> dice(7, 0);
  int maxCnt = 0;
  int maxNum;

  for (int i = 0; i < 3; i++)
  {
    int num;
    cin >> num;

    dice[num]++;
    if (maxCnt < dice[num])
    {
      maxCnt = dice[num];
      maxNum = num;
    }
    else if (maxCnt == dice[num] && maxNum < num)
    {
      maxNum = num;
    }
  }

  if (maxCnt == 1)
    cout << maxNum * 100 << endl;
  else if (maxCnt == 2)
    cout << 1000 + maxNum * 100 << endl;
  else
    cout << 10000 + maxNum * 1000 << endl;
}

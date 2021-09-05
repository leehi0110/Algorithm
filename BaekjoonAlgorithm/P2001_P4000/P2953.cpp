// ProblemNumber || ProblemName : P2953 - 나는 요리사다
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

  int maxScore = -1;
  int maxIdx = 1;

  for (int i = 0; i < 5; i++)
  {

    int sumScore = 0;

    for (int j = 0; j < 4; j++)
    {

      int score;
      cin >> score;

      sumScore += score;
    }

    if (sumScore > maxScore)
    {
      maxScore = sumScore;
      maxIdx = i;
    }
  }

  cout << maxIdx + 1 << " " << maxScore << endl;
}

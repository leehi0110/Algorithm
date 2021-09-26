// ProblemNumber || ProblemName : P5597 - 과제 안내신 분?
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

  vector<bool> student(31, false);

  for (int i = 0; i < 28; i++)
  {
    int n;

    cin >> n;

    student[n] = true;
  }

  for (int i = 1; i <= 30; i++)
  {
    if (student[i] == false)
      cout << i << endl;
  }
}

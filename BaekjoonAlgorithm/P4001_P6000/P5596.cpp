// ProblemNumber || ProblemName : P5596 - 시험 점수
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int sumA = 0;
  int sumB = 0;

  for(int i=0;i<4;i++) {
    int a;
    cin >> a;

    sumA += a;
  }

    for(int i=0;i<4;i++) {
    int a;
    cin >> a;

    sumB += a;
  }

  if(sumA < sumB) cout << sumB << endl;
  else cout << sumA << endl;

}
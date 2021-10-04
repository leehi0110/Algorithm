// ProblemNumber || ProblemName : P1357 - 뒤집힌 덧셈
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

int Rev(int x);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int x, y;

  cin >> x >> y;

  cout << Rev(Rev(x) + Rev(y)) << endl;
}

int Rev(int x) {
  int returnVal = 0;

  while(1) {
    if(x < 10) {
      returnVal += x;
      break;
    }

    returnVal += (x%10);
    returnVal *= 10;
    x /= 10;
  }
  return returnVal;
} 
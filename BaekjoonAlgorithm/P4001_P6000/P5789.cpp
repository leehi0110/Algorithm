// ProblemNumber || ProblemName : P5789 - 한다 안한다
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

  string original;
  int halfIdx;
  int testCase;

  cin >> testCase;

  for(int i=0;i<testCase;i++) {
    cin >> original;

    halfIdx = original.length()/2;

    if(original[halfIdx] == original[halfIdx-1]) cout << "Do-it" << endl;
    else cout << "Do-it-Not" << endl;
  }
}
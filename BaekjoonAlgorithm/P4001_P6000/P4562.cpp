// ProblemNumber || ProblemName : P4562 - No Brainer
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

  int testCase;

  cin >> testCase;

  for(int i=0;i<testCase;i++) {
    int x , y;

    cin >> x >> y;

    if(x < y) cout << "NO BRAINS" << endl;
    else cout << "MMM BRAINS" << endl;
  }
}
// ProblemNumber || ProblemName : P9295 - 주사위
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

  for(int i=1;i<=testCase;i++) {
    int a, b;

    cin >> a >> b;

    cout << "Case " << i << ": " << a + b << endl;
  }
}
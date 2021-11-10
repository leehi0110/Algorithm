// ProblemNumber || ProblemName : P9085 - 더하기
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
    int n;
    int sum = 0;

    cin >> n;

    for(int j=0;j<n;j++) {
      int a;
      
      cin >> a;
      sum += a;
    }
    cout << sum << endl;
  }
}
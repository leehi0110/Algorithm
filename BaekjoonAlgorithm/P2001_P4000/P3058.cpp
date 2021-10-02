// ProblemNumber || ProblemName : P3058 - 짝수를 찾아라
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
    int min = 1e9;
    int sum = 0;

    for(int j=0;j<7;j++) {
      int num;
      cin >> num;

      if(num%2 == 0) {
        if(min > num) min = num;
        sum += num;
      }
    }
    
    cout << sum << " " << min << endl;
  }
}
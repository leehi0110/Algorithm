// ProblemNumber || ProblemName : P4592 - 중복을 없애자
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

  while(1) {
    int n;

    cin >> n;
    if(n == 0) break;
    else {
      int pre;
      cin >> pre;
      cout << pre << " ";
      for(int i=1;i<n;i++) {
        int num;
        cin >> num;

        if(num == pre) continue;
        else {
          pre = num;
          cout << pre << " ";
        }
      }
      cout << "$\n";
    }
  }
}
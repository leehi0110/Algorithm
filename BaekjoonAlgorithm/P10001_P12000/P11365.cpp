// ProblemNumber || ProblemName : P11365 - !밀비 급일
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
    string reverseStr;

    getline(cin, reverseStr);

    if(reverseStr == "END") break;
    else {
      for(int i=reverseStr.length()-1;i>=0;i--) {
        cout<< reverseStr[i];
      }
      cout << endl;
    }
  }
}
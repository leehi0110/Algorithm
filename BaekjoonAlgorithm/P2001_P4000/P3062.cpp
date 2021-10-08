// ProblemNumber || ProblemName : P3062 - 수 뒤집기
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

void solve();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;

  cin >> testCase;

  for(int i=0;i<testCase;i++) {
    solve();
  }
}

void solve()
{
  string str;
  string reverseStr = "";
  string sumStr;

  cin >> str;
  
  for(int i=str.length()-1;i>=0;i--) {
    reverseStr += str[i];
  }

  sumStr = to_string(stoi(str) + stoi(reverseStr));

  int startIdx = 0;
  int endIdx = sumStr.length()-1;
  bool resultBool = true;

  while(startIdx <= endIdx) {
    if(sumStr[startIdx] != sumStr[endIdx]) {
      resultBool = false;
      break;
    } else {
      startIdx ++;
      endIdx--;
    }
  }

  if(resultBool) cout << "YES" << endl;
  else cout << "NO" << endl;
}
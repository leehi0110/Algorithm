// ProblemNumber || ProblemName : P5026 - 박사 과정
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

void solve() {

  string str;
  string a = "" , b = "";

  cin >> str;

  for(int i=0;i<str.length();i++) {
    if(str[i] == 'P') {
      cout << "skipped" << endl;
      return;
    } else if(str[i] == '+') {
      a = str.substr(0,i);
      b = str.substr(i, str.length());

      cout << stoi(a) + stoi(b) << endl;
      return;
    }
  }
}
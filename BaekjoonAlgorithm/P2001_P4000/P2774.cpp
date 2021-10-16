// ProblemNumber || ProblemName : P2774 - 아름다운 수
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
  vector<int> numCnt(10,0);
  string str;
  int result = 0;

  cin >> str;

  for(int i=0;i<str.length();i++) {
    numCnt[str[i] - '0']++;
  }

  for(int i=0;i<10;i++) {
    if(numCnt[i] != 0) result++;
  }

  cout << result << endl;
}
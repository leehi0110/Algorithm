// ProblemNumber || ProblemName : P10205 - 헤라클레스와 히드라
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

    int head;
    string cmd;

    cin >> head;
    cin >> cmd;

    cout << "Data Set " << i+1 << ":" << endl;

    for(int i=0;i<cmd.length();i++) {
      if(cmd[i] == 'b') {
        head--;
      } else {
        head++;
      }
    }

    cout << head << endl;
    cout << endl;
  }
}
// ProblemNumber || ProblemName : P2711 - 오타맨 고창영
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
    int misIdx;
    string str;

    cin >> misIdx;
    cin >> str;

    for(int j=0;j<str.length();j++) {
      if(j+1 == misIdx) continue;
      else cout << str[j];
    }
    cout << endl;
  }
}
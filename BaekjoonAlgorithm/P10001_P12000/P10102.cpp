// ProblemNumber || ProblemName : P10102 - 개표
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

  string str;
  int temp;
  int aCnt = 0, bCnt = 0;

  cin >> temp;
  cin >> str;

  for(int i=0;i<str.length();i++) {
    if(str[i] == 'A') aCnt++;
    else bCnt++;
  }

  if(aCnt == bCnt) cout << "Tie" << endl;
  else if(aCnt > bCnt) cout << "A" << endl;
  else cout << "B" << endl;

}
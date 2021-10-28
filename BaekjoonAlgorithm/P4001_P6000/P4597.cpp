// ProblemNumber || ProblemName : P4597 - 패리티
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
    string str;
    int len;
    int cnt = 0;

    cin >> str;

    if(str == "#") break;

    len = str.length();

    for(int i=0;i<len-1;i++) {
      if(str[i] == '1') cnt++;
    }

    if(str[len-1] == 'e') {
      if(cnt%2 == 0) str[len-1] = '0';
      else str[len-1] = '1';
    } else {
      if(cnt%2 == 0) str[len-1] = '1';
      else str[len-1] = '0';
    }
    
    cout << str << endl;
  }
}
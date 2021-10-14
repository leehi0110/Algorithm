// ProblemNumber || ProblemName : P14909 - 양수 개수 세기
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
  string temp = "";
  int result = 0;

  getline(cin, str);

  for(int i=0;i<str.length();i++) {
    if(str[i] == ' ') {
      if(stoi(temp) > 0) result++;

      temp = "";
    } else temp += str[i];

    if(str.length() - 1 == i) {
      if(stoi(temp) >  0) result++;
    }
  }

  cout << result << endl;
}
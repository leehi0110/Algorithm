// ProblemNumber || ProblemName : P11023 - 더하기 3
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
  int sum = 0;
  
  getline(cin, str);

  for(int i=0;i<str.length();i++) {
    if(str[i] == ' ') {
      sum += stoi(temp);
      temp = "";
    } else {
      temp += str[i];
    }

    if(i == str.length() - 1) {
      sum += stoi(temp);
    }
  }

  cout << sum << endl;
}
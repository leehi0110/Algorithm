// ProblemNumber || ProblemName : P14912 - 숫자 빈도수
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

  int n;
  int result = 0;
  char tar;

  cin >> n;
  cin >> tar;

  for(int i=0;i<=n;i++) {
    string str = to_string(i);

    for(int j=0;j<str.length();j++) {
      if(str[j] == tar) result++;
    }
  }

  cout << result << endl;
}
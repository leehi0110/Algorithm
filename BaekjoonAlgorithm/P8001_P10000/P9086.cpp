// ProblemNumber || ProblemName : P9086 - 문자열
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;
  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    string temp;
    cin >> temp;

    cout << temp[0] << temp[temp.length() - 1] << endl;
  }
}

// ProblemNumber || ProblemName : P22966 - 가장 쉬운 문제를 찾는 문제
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
  int rowGrade = 6;
  string result;

  cin >> n;

  for(int i=0;i<n;i++) {
    string temp;
    int grade;

    cin >> temp;
    cin >> grade;

    if(grade < rowGrade) {
      rowGrade = grade;
      result = temp;
    }
  }

  cout << result << endl;
}
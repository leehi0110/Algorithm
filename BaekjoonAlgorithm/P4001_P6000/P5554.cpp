// ProblemNumber || ProblemName : P5554 - 심부름 가는 길
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
  
  int sum = 0;

  for(int i=0;i<4;i++) {
    int num;
    cin >> num;

    sum += num;
  }
  
  int min = sum/60;
  int sec = sum - (min*60);

  cout << min << endl;
  cout << sec << endl;
}
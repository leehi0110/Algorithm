// ProblemNumber || ProblemName : P2845 - 파티가 끝나고 난 뒤
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

  int n, p;
  int maxPer;
  vector<int> result;

  cin >> n >> p;

  maxPer = n * p;

  for(int i=0;i<5;i++) {
    int a;

    cin >> a;

    result.push_back(a - maxPer);
  }

  for(int i=0;i<result.size();i++) {
    cout << result[i] << " ";
  }
  cout << endl;

}
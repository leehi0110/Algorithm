// ProblemNumber || ProblemName : P2501 - 약수 구하기
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

  int n, k;

  vector<int> vec;
  
  cin >> n >> k;

  for(int i=n;i>0;i--) {
    if(n%i == 0) {
      vec.push_back(i);
    }
  }

  sort(vec.begin(),vec.end());

  if(vec.size() < k) cout << 0 << endl;
  else cout << vec[k-1] << endl;
}
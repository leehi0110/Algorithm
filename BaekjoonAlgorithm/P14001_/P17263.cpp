// ProblemNumber || ProblemName : P17263 - Sort 마스터 배지훈
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

  priority_queue<int> pq;
  int n;

  cin >> n;

  for(int i=0;i<n;i++) {
    int num;

    cin >> num;

    pq.push(num);
  }

  cout << pq.top() << endl;
}
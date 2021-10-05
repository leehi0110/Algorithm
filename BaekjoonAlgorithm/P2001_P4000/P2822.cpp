// ProblemNumber || ProblemName : P2822 - 점수 계산
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

  priority_queue<pair<int,int>> pq;
  priority_queue<int> order;
  int sum = 0;

  for(int i=1;i<=8;i++) {
    int score;
    cin >> score;

    pq.push({score,i});
  }

  for(int i=0;i<5;i++) {
    int score = pq.top().first;
    int idx = pq.top().second;

    pq.pop();

    sum += score;
    order.push(-idx);
  }

  cout << sum << endl;
  while(!order.empty()) {
    cout << -order.top() << " ";
    order.pop();
  }
  cout << endl;
}
// ProblemNumber || ProblemName : P11004 - K번째 수
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  priority_queue<int> pq;

  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    int temp;

    cin >> temp;

    if (pq.size() < k)
    {
      pq.push(temp);
    }
    else
    {
      int kNumber = pq.top();

      if (temp < kNumber)
      {
        pq.pop();
        pq.push(temp);
      }
    }
  }

  cout << pq.top() << endl;
}
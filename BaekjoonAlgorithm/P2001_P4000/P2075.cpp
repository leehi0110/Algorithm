// ProblemNumber || ProblemName : P2075 - N번째 큰 수

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
  priority_queue<int> que;

  int n;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int num;
      cin >> num;

      if (que.size() < n)
      {
        que.push(-1 * num);
      }
      else
      {
        int top = que.top() * -1;
        if (top < num)
        {
          que.pop();
          que.push(num * -1);
        }
      }
    }
  }

  cout << -1 * que.top() << endl;
}

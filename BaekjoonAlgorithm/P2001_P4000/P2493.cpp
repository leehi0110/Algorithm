// ProblemNumber || ProblemName : P2493 - 탑
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> result(n + 1, 0);
  vector<int> height(n + 1, -1);

  stack<pair<int, int>> saveStack;

  for (int i = 1; i <= n; i++)
  {
    cin >> height[i];
  }

  for (int i = height.size() - 1; i >= 1; i--)
  {
    int nowHeight = height[i];

    if (!saveStack.empty())
    {
      while (!saveStack.empty() && saveStack.top().first <= nowHeight)
      {
        result[saveStack.top().second] = i;
        saveStack.pop();
      }
    }

    if (nowHeight <= height[i - 1])
    {
      result[i] = i - 1;
    }
    else
    {
      saveStack.push({nowHeight, i});
    }
  }

  for (int i = 1; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;
}

// ProblemNumber || ProblemName : P10845 - 큐

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

  int n;
  queue<int> que;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    string cmd;
    int num;

    cin >> cmd;

    if (cmd == "push")
    {
      cin >> num;
      que.push(num);
    }
    else if (cmd == "pop")
    {
      if (que.empty())
        cout << -1 << endl;
      else
      {
        cout << que.front() << endl;
        que.pop();
      }
    }
    else if (cmd == "size")
    {
      cout << que.size() << endl;
    }
    else if (cmd == "empty")
    {
      if (que.empty())
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
    else if (cmd == "front")
    {
      if (que.empty())
        cout << -1 << endl;
      else
        cout << que.front() << endl;
    }
    else if (cmd == "back")
    {
      if (que.empty())
        cout << -1 << endl;
      else
        cout << que.back() << endl;
    }
  }
}

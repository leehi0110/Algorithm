// ProblemNumber || ProblemName : P1516 - 게임 개발
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int buildTime[501];
int minBuildTime[501];
int in[501];
vector<vector<int>> tp(501);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  queue<int> que;

  cin >> n;

  for (int i = 1; i <= n; i++)
  {

    cin >> buildTime[i];

    while (1)
    {
      int temp;
      cin >> temp;
      if (temp == -1)
        break;
      else
      {
        tp[temp].push_back(i); //
        in[i]++;
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (in[i] == 0)
    {
      que.push(i);
    }
  }

  while (!que.empty())
  {
    int now = que.front();

    que.pop();

    minBuildTime[now] += buildTime[now];

    for (int i = 0; i < tp[now].size(); i++)
    {
      int next = tp[now][i];
      minBuildTime[next] = max(minBuildTime[next], minBuildTime[now]);
      in[next]--;

      if (in[next] == 0)
        que.push(next);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << minBuildTime[i] << endl;
  }
}

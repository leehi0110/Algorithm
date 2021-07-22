// ProblemNumber || ProblemName : P1005 - ACM Craft
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

void topology();

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    topology();
  }
}

void topology()
{
  int n, k;

  cin >> n >> k;

  vector<int> time(n + 1, 0);
  vector<int> minTime(n + 1, 0);
  vector<int> in(n + 1, 0);
  int target;
  queue<int> que;

  vector<vector<int>> tp(n + 1);

  for (int i = 1; i <= n; i++)
  {
    cin >> time[i];
  }

  for (int i = 0; i < k; i++)
  {
    int x, y; // x 다음에 y를 지을 수 있다.

    cin >> x >> y;

    in[y]++;
    tp[x].push_back(y); // x를 지어야 y를 지을 수 있다.
  }

  for (int i = 1; i <= n; i++)
  {
    if (in[i] == 0)
      que.push(i);
  }

  while (!que.empty())
  {
    int now = que.front();

    que.pop();

    minTime[now] += time[now];

    for (int i = 0; i < tp[now].size(); i++)
    {
      int next = tp[now][i];

      minTime[next] = max(minTime[next], minTime[now]);
      in[next]--;

      if (in[next] == 0)
        que.push(next);
    }
  }

  cin >> target;

  cout << minTime[target] << endl;
}

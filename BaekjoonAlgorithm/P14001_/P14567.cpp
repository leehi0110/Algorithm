// ProblemNumber || ProblemName : P14567 - 선수과목
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  vector<int> in(n + 1, 0);
  vector<vector<int>> tp(n + 1);
  vector<int> semester(n + 1, 0);
  queue<pair<int, int>> que;

  for (int i = 0; i < m; i++)
  {
    int a, b;

    cin >> a >> b;
    in[b]++;
    tp[a].push_back(b);
  }

  for (int i = 1; i < in.size(); i++)
  {
    if (in[i] == 0)
    {
      que.push({i, 0});
    }
  }

  while (!que.empty())
  {
    int now = que.front().first;
    int seme = que.front().second;

    que.pop();

    semester[now] = seme + 1;

    for (int i = 0; i < tp[now].size(); i++)
    {
      int next = tp[now][i];

      in[next]--;
      if (in[next] == 0)
      {
        que.push({next, seme + 1});
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << semester[i] << " ";
  }
  cout << endl;
}

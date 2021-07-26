// ProblemNumber || ProblemName : P1766 - 문제집
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

  int n, m;
  int in[100001];
  vector<vector<int>> tp(32001);
  vector<int> result;
  priority_queue<int> pq;

  cin >> n >> m;

  for (int i = 0; i <= n; i++)
  {
    in[i] = 0;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    in[b]++;
    tp[a].push_back(b);
  }

  for (int i = 1; i <= n; i++)
  {
    if (in[i] == 0)
    {
      pq.push(-i);
    }
  }

  while (!pq.empty())
  {
    int now = -pq.top();
    pq.pop();

    result.push_back(now);

    for (int i = 0; i < tp[now].size(); i++)
    {
      int next = tp[now][i];

      in[next]--;

      if (in[next] == 0)
        pq.push(-next);
    }
  }

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;
}

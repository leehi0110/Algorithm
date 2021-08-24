// ProblemNumber || ProblemName : P2637 - 장난감 조립
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int tool[301];
int in[301];
vector<vector<int>> dp(301, vector<int>(301, 0));
vector<vector<pair<int, int>>> tp(301);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<int> pq;

  cin >> n >> m;

  for (int i = 0; i < 301; i++)
  {
    tool[i] = 0;
    in[i] = 0;
  }

  for (int i = 0; i < m; i++)
  {
    int x, y, z;
    // x를 만들기 위해 y개가 z개 필요하다

    cin >> x >> y >> z;
    in[x]++;
    tp[y].push_back({x, z});
  }

  for (int i = 1; i <= n; i++)
  {
    if (in[i] == 0)
    {
      pq.push(-i);
      dp[i][i] = 1;
    }
  }

  while (!pq.empty())
  {
    int now = -pq.top();
    pq.pop();

    for (int i = 0; i < tp[now].size(); i++)
    {
      int next = tp[now][i].first;
      int need = tp[now][i].second;

      in[next]--;
      for (int j = 0; j < dp[now].size(); j++)
      {
        dp[next][j] += dp[now][j] * need;
      }

      if (in[next] == 0)
      {
        pq.push(-next);
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (dp[n][i] != 0)
    {
      cout << i << " " << dp[n][i] << endl;
    }
  }
}

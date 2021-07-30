// ProblemNumber || ProblemName : P17396 - 백도어
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 9223372036854775807
typedef long long ll;

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  vector<int> view(n); // 시야정보
  vector<ll> dist(n, INF);
  vector<vector<pair<int, ll>>> graph(n);
  priority_queue<pair<ll, int>> pq;

  for (int i = 0; i < n; i++)
  {
    cin >> view[i];
  }

  view[n - 1] = 0; // 상대 넥서스는 보여도 갈 수 있다.

  for (int i = 0; i < m; i++)
  {
    int a, b;
    ll cost;

    cin >> a >> b;
    cin >> cost;

    graph[a].push_back({b, cost});
    graph[b].push_back({a, cost});
  }

  dist[0] = 0;
  pq.push({0, 0});

  while (!pq.empty())
  {
    ll nowCost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if (dist[now] < nowCost)
      continue;

    for (int i = 0; i < graph[now].size(); i++)
    {
      int next = graph[now][i].first;
      ll nextCost = graph[now][i].second;

      if (!view[next] && dist[next] > nowCost + nextCost)
      {
        dist[next] = nowCost + nextCost;
        pq.push({-dist[next], next});
      }
    }
  }

  if (dist[n - 1] >= INF)
    cout << -1 << endl;
  else
    cout << dist[n - 1] << endl;
}

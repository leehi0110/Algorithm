// ProblemNumber || ProblemName : P14284 - 간선 이어가기 2
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int s, t;
  int minCost = INF;

  cin >> n >> m;

  vector<int> dist(n + 1, INF);
  vector<vector<pair<int, int>>> graph(n + 1);
  priority_queue<pair<int, int>> pq;
  priority_queue<pair<int, int>> destpq;

  for (int i = 0; i < m; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  cin >> s >> t;

  dist[s] = 0;
  pq.push({0, s});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    for (int i = 0; i < graph[now].size(); i++)
    {
      int next = graph[now][i].first;
      int nextCost = graph[now][i].second;

      if (next == t)
      {
        destpq.push({-nextCost, now});
      }
      else
      {
        if (dist[next] <= cost + nextCost)
          continue;
        else
        {
          dist[next] = cost + nextCost;
          pq.push({-dist[next], next});
        }
      }
    }
  }

  while (!destpq.empty())
  {
    int cost = -destpq.top().first;
    int x = destpq.top().second;

    destpq.pop();

    if (dist[x] + cost < minCost)
      minCost = dist[x] + cost;
  }

  cout << minCost << endl;
}

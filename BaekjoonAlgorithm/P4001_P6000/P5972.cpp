// ProblemNumber || ProblemName : P5972 - 택배 배송
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1e9

using namespace std;
int dist[50001];
vector<vector<pair<int, int>>> graph(50001);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  priority_queue<pair<int, int>> pq;

  cin >> n >> m;

  for (int i = 0; i <= n; i++)
  {
    dist[i] = INF;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  dist[1] = 0;
  pq.push({0, 1});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if (dist[now] < cost)
      continue;

    for (int i = 0; i < graph[now].size(); i++)
    {
      int next = graph[now][i].first;
      int nextCost = graph[now][i].second;

      if (dist[next] > cost + nextCost)
      {
        dist[next] = cost + nextCost;
        pq.push({-dist[next], next});
      }
    }
  }

  cout << dist[n] << endl;
}

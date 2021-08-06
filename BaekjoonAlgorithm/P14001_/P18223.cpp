// ProblemNumber || ProblemName : P18223 - 민준이와 마산 그리고 건우
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

int v, e, p;
vector<vector<pair<int, int>>> graph(5001);

int Dijkstra(int start, int end);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> v >> e >> p;

  for (int i = 0; i < e; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  if (Dijkstra(1, v) < Dijkstra(1, p) + Dijkstra(p, v))
    cout << "GOOD BYE" << endl;
  else
    cout << "SAVE HIM" << endl;
}

int Dijkstra(int start, int end)
{
  priority_queue<pair<int, int>> pq;
  vector<int> dist(v + 1, INF);

  pq.push({0, start});
  dist[start] = 0;

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

      if (dist[next] <= cost + nextCost)
        continue;
      else
      {
        dist[next] = cost + nextCost;
        pq.push({-dist[next], next});
      }
    }
  }

  return dist[end];
}

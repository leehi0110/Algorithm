// ProblemNumber || ProblemName : P1240 - 노드사이의 거리

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1e9

using namespace std;
void dijkstra(vector<vector<pair<int, int>>> graph, int start, int end);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  vector<vector<pair<int, int>>> graph(n + 1);

  for (int i = 0; i < n - 1; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;

    cin >> a >> b;

    dijkstra(graph, a, b);
  }
}

void dijkstra(vector<vector<pair<int, int>>> graph, int start, int end)
{
  vector<int> dist(graph.size(), INF);
  priority_queue<pair<int, int>> pq;

  dist[start] = 0;

  for (int i = 0; i < graph[start].size(); i++)
  {
    int next = graph[start][i].first;
    int cost = graph[start][i].second;

    pq.push({-cost, next});
  }

  while (!pq.empty())
  {
    int next = pq.top().second;
    int cost = -pq.top().first;

    pq.pop();

    if (dist[next] < cost)
      continue;

    dist[next] = cost;

    for (int i = 0; i < graph[next].size(); i++)
    {
      int totalCost = cost + graph[next][i].second;
      int nnext = graph[next][i].first;

      if (dist[nnext] > totalCost)
      {
        pq.push({-totalCost, nnext});
      }
    }
  }

  cout << dist[end] << endl;
}

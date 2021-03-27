// ProblemNumber || ProblemName : 1504 - 특정한 최단 경로

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1e9

using namespace std;

int N, E;
int first, second;
int result = 0;

int firstCase = 0;
int secondCase = 0;

void dijkstra(vector<vector<pair<int, int>>> graph, int start, int end);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> E;

  vector<vector<pair<int, int>>> graph(N + 1);

  for (int i = 0; i < E; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  cin >> first >> second;

  dijkstra(graph, 1, first);
  dijkstra(graph, first, second);
  dijkstra(graph, second, N);

  if (result == INF)
    cout << -1 << endl;
  else
    cout << result << endl;
}

void dijkstra(vector<vector<pair<int, int>>> graph, int start, int end)
{
  priority_queue<pair<int, int>> pq;
  vector<int> distance(N + 1, INF);

  pq.push({0, start});
  distance[start] = 0;

  while (!pq.empty())
  {
    int dis = -pq.top().first;
    int next = pq.top().second;
    pq.pop();

    if (distance[next] < dis)
      continue;

    for (int i = 0; i < graph[next].size(); i++)
    {
      int cost = distance[next] + graph[next][i].second;

      if (distance[graph[next][i].first] > cost)
      {
        distance[graph[next][i].first] = cost;
        pq.push({-cost, graph[next][i].first});
      }
    }
  }

  result += distance[end];
}

// 순서에 유념해서 다시 작성
// 1 -> first vertex -> second Vertex -> N vertex
// 2 -> second vertex -> first Vertex -> N vertex
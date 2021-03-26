// ProblemNumber || ProblemName : 1753 - 최단 경로

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1e9

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int v, e;
  int start;
  priority_queue<pair<int, int>> pq;

  cin >> v >> e;

  vector<vector<pair<int, int>>> graph(v + 1);
  vector<int> distance(v + 1, INF);

  cin >> start;

  for (int i = 0; i < e; i++)
  {
    int startPoint, endPoint, weight;

    cin >> startPoint >> endPoint >> weight;

    graph[startPoint].push_back(pair<int, int>(endPoint, weight));
  }

  pq.push({0, start});
  distance[start] = 0;

  while (!pq.empty())
  {
    int dis = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if (distance[now] < dis)
      continue;

    for (int i = 0; i < graph[now].size(); i++)
    {
      int cost = distance[now] + graph[now][i].second;

      if (distance[graph[now][i].first] > cost)
      {
        distance[graph[now][i].first] = cost;
        pq.push({-cost, graph[now][i].first});
      }
    }
  }

  for (int i = 1; i < distance.size(); i++)
  {
    if (distance[i] == INF)
      cout << "INF\n";
    else
      cout << distance[i] << "\n";
  }
}

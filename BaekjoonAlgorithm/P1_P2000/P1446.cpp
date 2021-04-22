// ProblemNumber || ProblemName : P1446 - 지름길

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
void dijkstra(vector<int> &distance, vector<vector<pair<int, int>>> &graph);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, d;

  cin >> n >> d;

  vector<int> distance(d + 1);
  vector<vector<pair<int, int>>> graph(d + 1);

  for (int i = 0; i < n; i++)
  {
    int start, end, cost;

    cin >> start >> end >> cost;

    if (end > d)
      continue;
    else if (end - start <= cost)
      continue;
    else
    {
      graph[start].push_back({end, cost});
    }
  }

  for (int i = 0; i <= d; i++)
  {
    distance[i] = i;
    graph[i].push_back({i + 1, 1});
  }

  dijkstra(distance, graph);

  cout << distance[d] << endl;
}

void dijkstra(vector<int> &distance, vector<vector<pair<int, int>>> &graph)
{
  priority_queue<pair<int, int>> pq;

  pq.push({0, 0});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int here = pq.top().second;

    pq.pop();

    if (distance[here] < cost)
      continue;

    for (int i = 0; i < graph[here].size(); i++)
    {
      int next = graph[here][i].first;
      int nextDistance = cost + graph[here][i].second;

      if (distance[next] > nextDistance)
      {
        distance[next] = nextDistance;
        pq.push({-nextDistance, next});
      }
    }
  }
}

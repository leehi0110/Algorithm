// ProblemNumber || ProblemName : 1916 최소비용 구하기

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

  int n, m, s, e;

  cin >> n >> m;

  vector<vector<pair<int, int>>> graph(n + 1);
  vector<int> distance(n + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  for (int i = 0; i < m; i++)
  {
    int start, end, cost;

    cin >> start >> end >> cost;
    graph[start].push_back({end, cost});
  }

  cin >> s >> e;

  pq.push({0, s});
  distance[s] = 0;

  while (!pq.empty())
  {
    int dist = pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if (distance[now] < dist)
      continue;

    for (int i = 0; i < graph[now].size(); i++)
    {
      int nextDist = graph[now][i].second;
      int next = graph[now][i].first;

      if (distance[next] > dist + nextDist)
      {
        distance[next] = dist + nextDist;
        pq.push({distance[next], next});
      }
    }
  }

  cout << distance[e] << endl;
}

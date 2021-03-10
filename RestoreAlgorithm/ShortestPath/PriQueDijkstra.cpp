// ProblemNumber || ProblemName : 우선순위 다익스트라 알고리즘₩₩

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, s;

  cin >> n >> m;
  cin >> s;

  vector<int> distance(n + 1, 99999);
  vector<vector<pair<int, int>>> graph(n + 1);
  priority_queue<pair<int, int>> que;

  for (int i = 0; i < m; i++)
  {
    int start, end, cost;

    cin >> start >> end >> cost;

    graph[start].push_back({end, cost});
  }

  que.push({0, s});
  distance[s] = 0;

  while (!que.empty())
  {
    int dis = -que.top().first;
    int now = que.top().second;

    que.pop();

    if (distance[now] < dis)
      continue;

    for (int i = 0; i < graph[now].size(); i++)
    {
      int cost = dis + graph[now][i].second;

      if (cost < distance[graph[now][i].first])
      {
        distance[graph[now][i].first] = cost;
        que.push(make_pair(-cost, graph[now][i].first));
      }
    }
  }

  for (int i = 1; i < distance.size(); i++)
  {
    cout << distance[i] << endl;
  }
}

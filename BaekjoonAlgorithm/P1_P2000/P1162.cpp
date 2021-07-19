// ProblemNumber || ProblemName : P1162 - 도로 포장
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

int n, m, k;
int dist[10001];
int result = 0;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;

  vector<vector<pair<int, int>>> graph(n + 1);
  priority_queue<int> costQue;
  vector<int> trace(n + 1);
  priority_queue<pair<int, int>> pq;

  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
  }

  for (int i = 0; i < m; i++)
  {
    int start, end, cost;

    cin >> start >> end >> cost;
    graph[start].push_back({end, cost});
    graph[end].push_back({start, cost});
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
        trace[next] = now;
        pq.push({-dist[next], next});
      }
    }
  }

  int now = n;
  int next = trace[now];

  while (1)
  {
    if (now == 1)
      break;

    for (int i = 0; i < graph[now].size(); i++)
    {
      if (graph[now][i].first == next)
      {
        costQue.push(graph[now][i].second);
        break;
      }
    }

    now = next;
    next = trace[now];
  }

  if (costQue.size() > k)
  {
    for (int i = 0; i < k; i++)
    {
      costQue.pop();
    }

    while (!costQue.empty())
    {
      result += costQue.top();
      costQue.pop();
    }
  }

  cout << result << endl;
}

// ProblemNumber || ProblemName : P20010 - 악덕 영주 혜유
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

int n, k;
int totalCost = 0;
int maxCost = 0;
int parent[1001];
vector<vector<pair<int, int>>> graph(1001);

void unionParent(int x, int y);
int findParent(int x);
void dijkstra(int start);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<int, pair<int, int>>> pq;

  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < k; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    pq.push({-c, {a, b}});
  }

  // 마을들을 연결하는 최소비용을 구함
  // 마을을 연결하는데 필요한 도로를 구함
  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if (findParent(x) != findParent(y))
    {
      unionParent(x, y);
      totalCost += cost;
      graph[x].push_back({y, cost});
      graph[y].push_back({x, cost});
    }
  }

  for (int i = 0; i < n; i++)
  {
    dijkstra(i);
  }

  cout << totalCost << endl;
  cout << maxCost << endl;
}

void dijkstra(int start)
{
  vector<int> dist(n, INF);
  priority_queue<pair<int, int>> pq;

  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

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

  for (int i = 0; i < n; i++)
  {
    if (maxCost < dist[i])
    {
      maxCost = dist[i];
    }
  }
}

int findParent(int x)
{
  if (parent[x] != x)
  {
    parent[x] = findParent(parent[x]);
  }

  return parent[x];
}

void unionParent(int x, int y)
{
  int parentX = findParent(x);
  int parentY = findParent(y);

  if (parentX > parentY)
    parent[parentX] = parentY;
  else
    parent[parentY] = parentX;
}

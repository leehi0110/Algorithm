// ProblemNumber || ProblemName : P14950 - 정복자
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m, k;
int totalCost = 0;
int times = 0;
int parent[10001];
vector<vector<pair<int, int>>> graph(10001);

void unionParent(int x, int y);
int findParent(int x);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<int, pair<int, int>>> pq;

  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  for (int i = 0; i < graph[1].size(); i++)
  {
    int next = graph[1][i].first;
    int cost = graph[1][i].second;

    pq.push({-cost, {1, next}});
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if (findParent(x) != findParent(y))
    {
      totalCost += (cost + (times * k));
      times++;
      unionParent(x, y);

      for (int i = 0; i < graph[y].size(); i++)
      {
        int next = graph[y][i].first;
        int nextCost = graph[y][i].second;

        pq.push({-nextCost, {y, next}});
      }
    }
  }

  cout << totalCost << endl;
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
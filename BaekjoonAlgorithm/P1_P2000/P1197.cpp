// ProblemNumber || ProblemName : P1197 - 최소 스패닝 트리

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
int findParent(int x);
void unionParent(int x, int y);

int parent[100001];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int vertex, edge;
  long long totalCost = 0;
  priority_queue<pair<int, pair<int, int>>> pq;

  cin >> vertex >> edge;

  // vector<int> parent(vertex + 1, 0);

  for (int i = 1; i <= vertex; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < edge; i++)
  {
    int a, b, cost;

    cin >> a >> b >> cost;
    pq.push({-cost, {a, b}});
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int a = pq.top().second.first;
    int b = pq.top().second.second;

    pq.pop();

    if (findParent(a) != findParent(b))
    {
      totalCost += cost;
      unionParent(a, b);
    }
  }

  cout << totalCost << "\n";
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

  if (parentX < parentY)
  {
    parent[parentY] = parentX;
  }
  else
  {
    parent[parentX] = parentY;
  }
}
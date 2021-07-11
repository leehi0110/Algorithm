// ProblemNumber || ProblemName : P16398 - 행성 연결
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

typedef long long ll;
#define INF 1e9

int table[1001][1001];
int parent[1001];

void unionParent(int x, int y);
int findParent(int x);

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  ll totalCost = 0;
  priority_queue<pair<int, pair<int, int>>> pq;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int cost;
      cin >> cost;

      table[i][j] = cost;
      table[j][i] = cost;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {

      if (i == j)
        continue;
      else
      {
        pq.push({-table[j][i], {i, j}});
      }
    }
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int a = pq.top().second.first;
    int b = pq.top().second.second;

    pq.pop();

    if (findParent(a) != findParent(b))
    {
      totalCost += static_cast<ll>(cost);
      unionParent(a, b);
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
  {
    parent[parentX] = parentY;
  }
  else
  {
    parent[parentY] = parentX;
  }
}
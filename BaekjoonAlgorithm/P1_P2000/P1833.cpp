// ProblemNumber || ProblemName : P1833 - 고속철도 설계하기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n;
int parent[201];
int table[201][201];
int totalCost = 0;

void unionParent(int x, int y);
int findParent(int x);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  priority_queue<pair<int, pair<int, int>>> pq;
  vector<pair<int, int>> newRoad;

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> table[i][j];
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = i + 1; j <= n; j++)
    {
      int cost = table[i][j];

      if (cost < 0)
      {
        unionParent(i, j);
        totalCost += -cost;
      }
      else
      {
        pq.push({-cost, {i, j}});
      }
    }
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if (findParent(x) != findParent(y))
    {
      totalCost += cost;
      unionParent(x, y);
      newRoad.push_back({x, y});
    }
  }

  cout << totalCost << " " << newRoad.size() << endl;
  for (int i = 0; i < newRoad.size(); i++)
  {
    cout << newRoad[i].first << " " << newRoad[i].second << endl;
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
  {
    parent[parentX] = parentY;
  }
  else
    parent[parentY] = parentX;
}

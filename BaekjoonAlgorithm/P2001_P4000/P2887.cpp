// ProblemNumber || ProblemName : P2887 - 행성터널
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
typedef long long ll;
using namespace std;

int n;
int parent[100001];

void unionParent(int x, int y);
int findParent(int x);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  vector<pair<ll, pair<ll, ll>>> vc;
  priority_queue<pair<ll, pair<int, int>>> pq;
  ll totalCost = 0;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    long long x, y, z;
    cin >> x >> y >> z;

    if (i != 1)
    {
      for (int j = 0; j < vc.size(); j++)
      {
        ll ax = vc[j].first;
        ll ay = vc[j].second.first;
        ll az = vc[j].second.second;

        ll cost = min({abs(x - ax), abs(y - ay), abs(z - az)});
        pq.push({-cost, {i, j + 1}});
      }
    }
    vc.push_back({x, {y, z}});
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
    parent[parentY] = parentX;
}

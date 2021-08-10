// ProblemNumber || ProblemName : P21924 - 도시 건설
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

typedef long long ll;
int n, m;
ll totalCost = 0;
ll minCost = 0;
vector<int> parent(100001, 0);

int findParent(int x);
void unionParent(int x, int y);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<ll, pair<int, int>>> pq;

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    ll c;

    cin >> a >> b;
    cin >> c;
    pq.push({-c, {a, b}});
    totalCost += c;
  }

  while (!pq.empty())
  {
    ll cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if (findParent(x) != findParent(y))
    {
      unionParent(x, y);
      minCost += cost;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    parent[i] = findParent(i);
  }

  if (*max_element(parent.begin() + 1, parent.end()) != 1)
    cout << -1 << endl;
  else
    cout << totalCost - minCost << endl;
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

int findParent(int x)
{
  if (parent[x] != x)
  {
    parent[x] = findParent(parent[x]);
  }

  return parent[x];
}

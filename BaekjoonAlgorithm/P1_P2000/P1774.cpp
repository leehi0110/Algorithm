// ProblemNumber || ProblemName : P1774 - 우주신과의 교감
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

int parent[1001];

void unionParent(int x, int y);
int findParent(int x);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  double totalDist = 0;

  cin >> n >> m;

  vector<pair<int, int>> vec(n + 1);
  priority_queue<pair<double, pair<int, int>>> pq;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> vec[i].first >> vec[i].second;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    unionParent(a, b);
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = i + 1; j <= n; j++)
    {
      if (findParent(i) != findParent(j))
      {
        int ix = vec[i].first;
        int iy = vec[i].second;

        int jx = vec[j].first;
        int jy = vec[j].second;

        double xyDist = sqrt(pow(ix - jx, 2) + pow(iy - jy, 2));

        pq.push({-xyDist, {i, j}});
      }
    }
  }

  while (!pq.empty())
  {
    double dist = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if (findParent(x) != findParent(y))
    {
      unionParent(x, y);
      totalDist += dist;
    }
  }

  cout << fixed;
  cout.precision(2);
  cout << totalDist << endl;
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

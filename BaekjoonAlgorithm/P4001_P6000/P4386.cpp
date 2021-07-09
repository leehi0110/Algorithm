// ProblemNumber || ProblemName : P4386 - 별자리 만들기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

int n;
int parent[101];

void unionParent(int x, int y);
int findParent(int x);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  vector<pair<double, double>> vec;
  priority_queue<pair<double, pair<int, int>>> pq;
  double totalCost = 0;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    double x, y;
    cin >> x >> y;

    if (i != 1)
    {

      for (int j = 0; j < vec.size(); j++)
      {
        double a = vec[j].first;
        double b = vec[j].second;

        double dist = sqrt(pow(x - a, 2) + pow(y - b, 2));

        pq.push({-dist, {i, j + 1}});
      }
    }
    vec.push_back({x, y});
  }

  while (!pq.empty())
  {
    double cost = -pq.top().first;
    int a = pq.top().second.first;
    int b = pq.top().second.second;

    pq.pop();

    if (findParent(a) != findParent(b))
    {
      unionParent(a, b);
      totalCost += cost;
    }
  }
  cout << fixed;
  cout.precision(2);
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

// (x, y) (a, b) 거리
// dist^2 = (x-a)^2 + (y-b)^2
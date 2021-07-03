// ProblemNumber || ProblemName : P10423 - 전기가 부족해
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int parent[1001];
int n, m, k;
vector<int> ele;

void unionParent(int x, int y);
int findParent(int x);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int totalCost = 0;
  priority_queue<pair<int, pair<int, int>>> pq;

  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < k; i++)
  {
    int temp;

    cin >> temp;

    ele.push_back(temp);
  }

  for (int i = 0; i < ele.size() - 1; i++)
  {
    if (findParent(ele[i]) != findParent(ele[i + 1]))
    {
      unionParent(ele[i], ele[i + 1]);
    }
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    pq.push({-c, {a, b}});
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int first = pq.top().second.first;
    int second = pq.top().second.second;

    pq.pop();

    if (findParent(first) != findParent(second))
    {
      totalCost += cost;
      unionParent(first, second);
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

// ProblemNumber || ProblemName : P1922 - 네트워크 연결

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int findParent(vector<int> parent, int x);
void unionParent(vector<int> &parent, int x, int y);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int sum = 0;

  cin >> n;
  cin >> m;

  vector<int> parent(n + 1, 0);
  priority_queue<pair<int, pair<int, int>>> pq;

  for (int i = 0; i <= n; i++)
  {
    parent[i] = i;
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
    int a = pq.top().second.first;
    int b = pq.top().second.second;

    pq.pop();

    if (findParent(parent, a) != findParent(parent, b))
    {
      sum += cost;
      unionParent(parent, a, b);
    }
  }

  cout << sum << endl;
}

void unionParent(vector<int> &parent, int x, int y)
{
  int parentX = findParent(parent, x);
  int parentY = findParent(parent, y);

  if (parentX < parentY)
  {
    parent[parentY] = parentX;
  }
  else
  {
    parent[parentX] = parentY;
  }
}

int findParent(vector<int> parent, int x)
{
  if (parent[x] != x)
  {
    parent[x] = findParent(parent, parent[x]);
  }

  return parent[x];
}
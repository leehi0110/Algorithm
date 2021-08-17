// ProblemNumber || ProblemName : P16562 - 친구비
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m;
long long k;
long long price[10001];
long long result = 0;
vector<int> parent(10001, 0);

int findParent(int x);
void unionParent(int x, int y);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<long long, int>> pq;

  cin >> n >> m;
  cin >> k;

  for (int i = 1; i <= n; i++)
  {
    cin >> price[i];
    pq.push({-price[i], i});
    parent[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    if (findParent(a) != findParent(b))
    {
      unionParent(a, b);
    }
  }

  while (!pq.empty())
  {
    long long cost = -pq.top().first;
    int x = pq.top().second;

    pq.pop();

    if (findParent(0) != findParent(x))
    {
      unionParent(0, x);
      result += cost;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    parent[i] = findParent(i);
  }

  if (*max_element(parent.begin(), parent.end()) != 0 || result > k)
    cout << "Oh no" << endl;
  else
    cout << result << endl;
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

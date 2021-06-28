// ProblemNumber || ProblemName : P6497 - 전력난
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 최소 스패닝 트리 혹은 집합 알고리즘을 풀기위해 전역 배열을 사용하는 것이 시간복잡도를 줄일 수 있다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
int parent[200001];
void MST(int n, int m);
int findParent(int x);
void unionParent(int x, int y);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  while (1)
  {
    int n, m;

    cin >> n >> m;

    if (n == 0 && m == 0)
      break;
    else
    {
      MST(n, m);
    }
  }
}

void MST(int n, int m)
{
  priority_queue<pair<int, pair<int, int>>> pq;
  int totalCost = 0;
  int saveCost = 0;

  for (int i = 1; i < n + 1; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;
    totalCost += c;

    pq.push({-c, {a, b}});
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int a = pq.top().second.first;
    int b = pq.top().second.second;

    pq.pop();

    if (findParent(a) != findParent(b))
    {
      unionParent(a, b);
      saveCost += cost;
    }
  }

  cout << totalCost - saveCost << endl;
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

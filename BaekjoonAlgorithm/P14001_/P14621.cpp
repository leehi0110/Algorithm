// ProblemNumber || ProblemName : P14621 - 나만 안되는 연애
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 반복문 내부에 조건문과 break를 설정할 때 범위 설정을 신중히 하자

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m;
char gender[1001];
int parent[1001];

void unionParent(int x, int y);
int findParent(int x);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<int, pair<int, int>>> pq;

  cin >> n >> m;
  int totalCost = 0;

  for (int i = 1; i <= n; i++)
  {
    cin >> gender[i];
  }

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, cost;
    cin >> a >> b >> cost;

    pq.push({-cost, {a, b}});
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int a = pq.top().second.first;
    int b = pq.top().second.second;

    pq.pop();

    if (findParent(a) != findParent(b) && gender[a] != gender[b])
    {
      totalCost += cost;
      unionParent(a, b);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (findParent(i) != 1)
    {
      cout << -1 << endl;
      break;
    }

    if (i == n)
      cout << totalCost << endl;
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
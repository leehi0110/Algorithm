// ProblemNumber || ProblemName : P1647 - 도시 분할 계획
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 시간초과에 대해 해결하기 위해 vector<int> parent가 아닌 전역 변수인 int parent[100001]을 사용했다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
int findParent(int x);
void unionParent(int x, int y);

int parent[100001];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int maxCost = 0;
  long long sumCost = 0;
  priority_queue<pair<int, pair<int, int>>> pq;

  cin >> n >> m;

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
    int to = pq.top().second.first;
    int from = pq.top().second.second;

    pq.pop();

    if (findParent(to) != findParent(from))
    {
      unionParent(to, from);
      sumCost += static_cast<long long>(cost);

      if (cost > maxCost)
        maxCost = cost;
    }
  }

  cout << sumCost - static_cast<long long>(maxCost) << endl;
}

int findParent(int x)
{
  if (parent[x] == x)
    return x;
  else
  {
    return parent[x] = findParent(parent[x]);
  }
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
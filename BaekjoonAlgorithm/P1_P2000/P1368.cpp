// ProblemNumber || ProblemName : P1368 - 물대기
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 가상의 정점을 추가해 논에 우물을 파는 비용을 연결비용으로 처리해 모두 연결될 수 있도록 처리한다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n;
int map[301][301];
int parent[301];
int result = 0;

void unionParent(int x, int y);
int findParent(int x);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<int, pair<int, int>>> pq;
  int price;

  cin >> n;

  for (int i = 0; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> price;
    pq.push({-price, {0, i}});
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> map[i][j];
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = i + 1; j <= n; j++)
    {
      pq.push({-map[i][j], {i, j}});
    }
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if (findParent(x) != findParent(y))
    {
      result += cost;
      unionParent(x, y);
    }
  }

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

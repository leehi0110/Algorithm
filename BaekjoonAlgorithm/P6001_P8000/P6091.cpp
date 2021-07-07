// ProblemNumber || ProblemName : P6091 - 핑크 플로이드
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n;
int original[1025][1025];
int parent[1025];
int cnt[1025];

int findParent(int x);
void unionParent(int x, int y);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<int, pair<int, int>>> pq;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = i; j <= n; j++)
    {
      if (i == j)
        continue;

      int num;
      cin >> num;

      pq.push({-num, {i, j}});
    }
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int a = pq.top().second.first;
    int b = pq.top().second.second;

    pq.pop();

    if (original[a][b] == 0 && findParent(a) != findParent(b))
    {
      original[a][b] = cost;
      original[b][a] = cost;
      cnt[a]++;
      cnt[b]++;
      unionParent(a, b);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << cnt[i] << " ";

    for (int j = 1; j <= n; j++)
    {
      if (original[i][j] != 0)
        cout << j << " ";
    }
    cout << endl;
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
  {
    parent[parentY] = parentX;
  }
}
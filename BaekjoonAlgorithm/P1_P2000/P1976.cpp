// ProblemNumber || ProblemName : P1976 - 여행가자
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 반복문 + 조건문을 사용할 때 Break 조건의 순서를 명확히 하자

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int parent[201];
int route[1001];

int findParent(int x);
void unionParent(int x, int y);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  cin >> m;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int path;

      cin >> path;

      if (path == 0)
        continue;
      else
      {
        if (findParent(i) != findParent(j))
        {
          unionParent(i, j);
        }
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    cin >> route[i];
  }

  for (int i = 1; i < m; i++)
  {
    if (findParent(route[i - 1]) != findParent(route[i]))
    {
      cout << "NO" << endl;
      break;
    }

    if (i == m - 1)
      cout << "YES" << endl;
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

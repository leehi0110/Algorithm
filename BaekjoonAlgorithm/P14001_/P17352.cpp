// ProblemNumber || ProblemName : P17352 - 여러분의 다리가 되어 드리겠습니다
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[300001];
int n;

void unionParent(int x, int y);
int findParent(int x);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < n - 2; i++)
  {
    int a, b;

    cin >> a >> b;

    if (findParent(a) != findParent(b))
    {
      unionParent(a, b);
    }
  }

  int save = findParent(1);
  int saveIdx = 1;

  for (int i = 2; i <= n; i++)
  {
    if (save != findParent(i))
    {
      cout << saveIdx << " " << i << endl;
      break;
    }
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

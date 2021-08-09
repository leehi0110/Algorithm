// ProblemNumber || ProblemName : P2606 - 바이러스
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];
int findParent(int x);
void unionParent(int x, int y);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int com, pair;
  int result = 0;

  cin >> com >> pair;

  for (int i = 1; i <= com; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < pair; i++)
  {
    int a, b;

    cin >> a >> b;
    if (findParent(a) != findParent(b))
      unionParent(a, b);
  }

  for (int i = 2; i <= com; i++)
  {
    if (findParent(i) == 1)
      result++;
  }

  cout << result << endl;
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

int findParent(int x)
{
  if (parent[x] != x)
  {
    parent[x] = findParent(parent[x]);
  }
  return parent[x];
}
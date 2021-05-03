// ProblemNumber || ProblemName : P1717 - 집합의 표현

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findParent(vector<int> &parent, int target);
void unionParent(vector<int> &parent, int x, int y);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  vector<int> parent(n + 1, 0);

  for (int i = 1; i < parent.size(); i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int cmd, a, b;

    cin >> cmd >> a >> b;

    if (cmd == 0)
    {
      if (findParent(parent, a) != findParent(parent, b))
        unionParent(parent, a, b);
    }
    else
    {
      if (findParent(parent, a) != findParent(parent, b))
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
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
    parent[parentX] = parentY;
}

int findParent(vector<int> &parent, int target)
{
  if (parent[target] != target)
  {
    parent[target] = findParent(parent, parent[target]);
  }

  return parent[target];
}

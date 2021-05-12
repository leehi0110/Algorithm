// ProblemNumber || ProblemName : P11724 - 연결 요소의 개수

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void unionParent(vector<int> &parent, int x, int y);
int findParent(vector<int> parent, int x);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;
  vector<int> parent(n + 1, 0);
  vector<int> result;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;

    cin >> a >> b;

    if (findParent(parent, a) != findParent(parent, b))
      unionParent(parent, a, b);
  }

  for (int i = 1; i < parent.size(); i++)
  {
    result.push_back(findParent(parent, i));
  }

  sort(result.begin(), result.end());

  result.erase(unique(result.begin(), result.end()), result.end());

  cout << result.size() << endl;
}

int findParent(vector<int> parent, int x)
{
  if (parent[x] != x)
  {
    parent[x] = findParent(parent, parent[x]);
  }
  return parent[x];
}

void unionParent(vector<int> &parent, int x, int y)
{
  int parentX = findParent(parent, x);
  int parentY = findParent(parent, y);

  if (parentX < parentY)
  {
    parent[parentY] = parentX;
  }
  else if (parentX > parentY)
  {
    parent[parentX] = parentY;
  }
}

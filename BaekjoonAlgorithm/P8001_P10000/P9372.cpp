// ProblemNumber || ProblemName : P9372 - 상근이의 여행

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void checkCase();
void unionParent(vector<int> &parent, int x, int y);
int findParent(vector<int> parent, int x);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    checkCase();
  }
}

void checkCase()
{
  int n, m;
  int answer = 0;

  cin >> n >> m;

  vector<int> parent(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;

    cin >> a >> b;

    if (findParent(parent, a) != findParent(parent, b))
    {
      answer++;
      unionParent(parent, a, b);
    }
  }

  cout << answer << endl;
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
  else
  {
    parent[parentX] = parentY;
  }
}

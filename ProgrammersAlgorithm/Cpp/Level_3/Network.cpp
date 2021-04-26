#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;
int findParent(vector<int> &parent, int target);
void unionParent(vector<int> &parent, int x, int y);

int solution(int n, vector<vector<int>> computers)
{
  int answer = 0;
  set<int> result;
  vector<int> parent(n);

  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < computers.size(); i++)
  {
    for (int j = 0; j < computers.size(); j++)
    {
      if (i == j)
        continue;
      else
      {
        if (computers[i][j] == 1 && computers[j][i] == 1)
        {
          if (findParent(parent, i) != findParent(parent, j))
            unionParent(parent, i, j);
        }
      }
    }
  }

  for (int i = 0; i < parent.size(); i++)
  {
    int temp = findParent(parent, i);
  }

  for (int i = 0; i < parent.size(); i++)
  {
    result.insert(parent[i]);
  }

  return result.size();
}

int findParent(vector<int> &parent, int target)
{
  if (parent[target] != target)
  {
    parent[target] = findParent(parent, parent[target]);
  }

  return parent[target];
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

int main()
{
  int result = solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}});
  // int result = solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}});

  cout << result << endl;
}
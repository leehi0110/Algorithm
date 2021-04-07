#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b);
int findParent(vector<int> &parent, int target);
void unionParent(vector<int> &parent, int x, int y);

int solution(int n, vector<vector<int>> costs)
{
  int answer = 0;
  vector<int> parent(n + 1, 0);

  for (int i = 1; i < n + 1; i++)
  {
    parent[i] = i;
  }

  sort(costs.begin(), costs.end(), compare);

  for (int i = 0; i < costs.size(); i++)
  {
    int start = costs[i][0], end = costs[i][1], cost = costs[i][2];

    if (findParent(parent, start) != findParent(parent, end))
    {
      unionParent(parent, start, end);
      answer += cost;
    }
  }

  return answer;
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

int findParent(vector<int> &parent, int target)
{
  if (parent[target] != target)
  {
    parent[target] = findParent(parent, parent[target]);
  }
  return parent[target];
}

bool compare(vector<int> a, vector<int> b)
{
  if (a[2] < b[2])
    return true;
  else
    return false;
}
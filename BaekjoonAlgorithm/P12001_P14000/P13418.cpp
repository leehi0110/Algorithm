// ProblemNumber || ProblemName : P13418 - 학교 탐방하기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

int parent[1001];
int maxK, minK;
int n, m;

void unionParent(int x, int y);
int findParent(int x);
void parentInit();

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<int, pair<int, int>>> minpq; // 내리막길을 우선으로 길을 만든다
  //
  priority_queue<pair<int, pair<int, int>>> maxpq; // 오리막길을 우선으로 길을 만든다

  cin >> n >> m;

  for (int i = 0; i <= m; i++)
  {
    int a, b, asc;

    // 0 오르막길, 1 내리막길
    cin >> a >> b >> asc;

    minpq.push({asc, {a, b}});  // 내리막길 우선
    maxpq.push({-asc, {a, b}}); // 오르막길 우선
  }

  parentInit();

  while (!minpq.empty())
  {
    int asc = minpq.top().first;
    int a = minpq.top().second.first;
    int b = minpq.top().second.second;

    minpq.pop();

    if (findParent(a) != findParent(b))
    {
      unionParent(a, b);
      if (asc == 0)
        minK++;
    }
  }

  parentInit();

  while (!maxpq.empty())
  {
    int asc = -maxpq.top().first;
    int a = maxpq.top().second.first;
    int b = maxpq.top().second.second;

    maxpq.pop();

    if (findParent(a) != findParent(b))
    {
      unionParent(a, b);
      if (asc == 0)
        maxK++;
    }
  }

  cout << pow(maxK, 2) - pow(minK, 2) << endl;
}

void parentInit()
{
  for (int i = 0; i <= n; i++)
  {
    parent[i] = i;
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

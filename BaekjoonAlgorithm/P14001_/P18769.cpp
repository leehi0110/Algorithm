// ProblemNumber || ProblemName : P18769 - 그리드 네트워크
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int parent[250001];

void solve();
void unionParent(int x, int y);
int findParent(int x);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;

  cin >> testCase;

  for(int i=0;i<testCase;i++) {
    solve();
  }
}

void solve()
{

  int r, c;
  int vertexNum = 1;
  int sumCost = 0;

  cin >> r >> c;

  vector<vector<pair<int,int>>> graph(r*c+1);
  priority_queue<pair<int,pair<int,int>>> pq;

  for(int i=1;i<=r*c;i++) parent[i] = i;

  for(int i=0;i<r;i++) {
    for(int j=0;j<c-1;j++) {
      int cost;
      cin >> cost;
      graph[vertexNum].push_back({vertexNum+1, cost});
      graph[vertexNum+1].push_back({vertexNum, cost});
      pq.push({-cost, {vertexNum, vertexNum+1}});
      vertexNum++;
    }
    vertexNum++;
  }

  vertexNum = 1;
  for(int i=0;i<r-1;i++) {
    for(int j=0;j<c;j++) {
      int cost;
      cin >> cost;

      graph[vertexNum].push_back({vertexNum + c, cost});
      graph[vertexNum+c].push_back({vertexNum, cost});
      pq.push({-cost, {vertexNum, vertexNum+c}});
      vertexNum++;
    }
    vertexNum++;
  }

  while(!pq.empty()) {
    int cost = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if(findParent(x) != findParent(y)) {
      unionParent(x, y);
      sumCost += cost;
    }
  }

  cout << sumCost << endl;

}

// (1) - 1 - (2) - 3 - (3)
// |          |         |
// 2          4         2
// |          |         |
// (4) - 3 - (5) - 1 - (6)

// 2 3
// 1 3
// 3 1
// 2 4 2

int findParent(int x) {
  if(parent[x] != x) {
    parent[x] = findParent(parent[x]);
  }

  return parent[x];
}

void unionParent(int x, int y) {
  int parentX = findParent(x);
  int parentY = findParent(y);

  if(parentX > parentY) parent[parentX] = parentY;
  else parent[parentY] = parentX;
}

// ProblemNumber || ProblemName : P14496 - 그대, 그머가 되어
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#define INF 1e9

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int start, end;
  int n, m;

  cin >> start >> end;
  cin >> n >> m;

  vector<vector<int>> graph(n+1);
  vector<int> dist(n+1, INF);
  priority_queue<pair<int,int>> pq;

  for(int i=0;i<m;i++) {
    int a, b;

    cin >> a >> b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dist[start] = 0;
  pq.push({0, start});

  while(!pq.empty()) {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    for(int i=0;i<graph[now].size();i++) {
      int next = graph[now][i];

      if(dist[next] <= cost + 1) continue;
      else {
        dist[next] = cost + 1;
        pq.push({-dist[next], next});
      }
    }
  }

  if(dist[end] == INF) cout << -1 << endl;
  else cout << dist[end] << endl;
}
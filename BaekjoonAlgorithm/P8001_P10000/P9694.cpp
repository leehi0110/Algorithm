// ProblemNumber || ProblemName : P9694 - 무엇을 아느냐보다 누구를 아느냐가 문제다
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9

int testCase;
int n, m;

using namespace std;

void solve(int caseNum);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    solve(i + 1);
  }
}

void solve(int caseNum)
{
  cin >> n >> m;
  vector<int> track(m);
  vector<vector<pair<int, int>>> graph(20);
  vector<int> dist(m, INF);
  priority_queue<pair<int, int>> pq;

  for (int i = 0; i < m; i++)
  {
    track[i] = i;
  }

  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;

    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  dist[0] = 0;
  pq.push({0, 0});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    for (int i = 0; i < graph[now].size(); i++)
    {
      int next = graph[now][i].first;
      int nextCost = graph[now][i].second;

      if (dist[next] <= cost + nextCost)
        continue;
      else
      {
        track[next] = now;
        dist[next] = cost + nextCost;
        pq.push({-dist[next], next});
      }
    }
  }

  if (dist[m - 1] == INF)
  {
    cout << "Case #" << caseNum << ": -1" << endl;
  }
  else
  {
    vector<int> route;
    int target = m - 1;

    route.push_back(target);

    while (target != 0)
    {
      target = track[target];
      route.push_back(target);
    }
    cout << "Case #" << caseNum << ": ";
    for (int i = route.size() - 1; i >= 0; i--)
    {
      cout << route[i];
      if (i != 0)
        cout << " ";
    }
    cout << endl;
  }
}

// ProblemNumber || ProblemName : P9370 - 미확인 도착지
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 최단거리가 같아서 g와 h사이의 간선을 지나가지 않는 경우도 고려해야된다.
// -> 특정 정점을 거치는지 확인할 경우 지나가는 정점들을 분할해서 생각하자

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9

using namespace std;

void solve();
vector<int> Dijkstra(vector<vector<pair<int, int>>> graph, int start);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    solve();
  }
}

void solve()
{
  // 정점의 개수, 간선의 개수, 목적지 후보의 개수
  int n, m, t;
  // 출발지, 꼭 지나간 간선이 이어진 정점 g and h
  int s, g, h;
  // 정점간의 연결에 대한 정보
  vector<vector<pair<int, int>>> graph(2001);
  vector<int> result;

  cin >> n >> m >> t;
  cin >> s >> g >> h;

  for (int i = 0; i < m; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  vector<int> dist_s = Dijkstra(graph, s);
  vector<int> dist_h = Dijkstra(graph, h);
  vector<int> dist_g = Dijkstra(graph, g);

  for (int i = 0; i < t; i++)
  {
    int target;
    cin >> target;

    if (dist_s[target] == (dist_s[g] + dist_g[h] + dist_h[target]) || dist_s[target] == (dist_s[h] + dist_h[g] + dist_g[target]))
      result.push_back(target);
  }

  sort(result.begin(), result.end());

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;
}

vector<int> Dijkstra(vector<vector<pair<int, int>>> graph, int start)
{
  vector<int> dist(2001, INF);
  priority_queue<pair<int, int>> pq;

  dist[start] = 0;
  pq.push({0, start});

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
        dist[next] = cost + nextCost;
        pq.push({-dist[next], next});
      }
    }
  }

  return dist;
}
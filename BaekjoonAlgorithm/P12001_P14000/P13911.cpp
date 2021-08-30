// ProblemNumber || ProblemName : P13911 - 집구하기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9

using namespace std;

int v, e;
int m, x;
int s, y;
int minDist = INF;
vector<int> mc;
vector<int> star;
vector<vector<pair<int, int>>> graph(10001);
// first = 맥날 최단거리 second = 스벅 최단거리

vector<int> Dijkstra(vector<int> store);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> v >> e;

  for (int i = 0; i < e; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  cin >> m >> x;

  for (int i = 0; i < m; i++)
  {
    int mcNum;
    cin >> mcNum;

    mc.push_back(mcNum);
  }

  cin >> s >> y;

  for (int i = 0; i < s; i++)
  {
    int startNum;
    cin >> startNum;

    star.push_back(startNum);
  }

  vector<int> mcDist = Dijkstra(mc);
  vector<int> starDist = Dijkstra(star);

  for (int i = 1; i <= v; i++)
  {
    if (mcDist[i] != 0 && starDist[i] != 0 && mcDist[i] <= x && starDist[i] <= y && minDist > mcDist[i] + starDist[i])
    {
      minDist = mcDist[i] + starDist[i];
    }
  }

  if (minDist == INF)
    cout << -1 << endl;
  else
    cout << minDist << endl;
}

vector<int> Dijkstra(vector<int> store)
{
  priority_queue<pair<int, int>> pq;
  vector<int> dist(v + 1, INF);

  for (int i = 0; i < store.size(); i++)
  {
    dist[store[i]] = 0;
    pq.push({0, store[i]});
  }

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    for (int i = 0; i < graph[now].size(); i++)
    {
      int next = graph[now][i].first;
      int nextCost = graph[now][i].second;

      if (dist[next] <= nextCost + cost)
        continue;
      else
      {
        dist[next] = nextCost + cost;
        pq.push({-dist[next], next});
      }
    }
  }
  return dist;
}

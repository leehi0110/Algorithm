// ProblemNumber || ProblemName : P22865 - 가장 먼 곳
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

int n;
int friends[3];
vector<vector<int>> friendsDist;
int m;
int farDist = -1;
int farLand;
vector<vector<pair<int, int>>> graph(100001);

void Dijkstra(int start);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < 3; i++)
  {
    cin >> friends[i];
  }
  cin >> m;

  for (int i = 0; i < m; i++)
  {
    int land_1, land_2, cost;

    cin >> land_1 >> land_2 >> cost;

    graph[land_1].push_back({land_2, cost});
    graph[land_2].push_back({land_1, cost});
  }

  for (int i = 0; i < 3; i++)
  {
    Dijkstra(friends[i]);
  }

  for (int i = 1; i <= n; i++)
  {
    int minDist = INF;
    for (int j = 0; j < 3; j++)
    {
      if (minDist > friendsDist[j][i])
      {
        minDist = friendsDist[j][i];
      }
    }
    if (farDist < minDist)
    {
      farDist = minDist;
      farLand = i;
    }
  }

  cout << farLand << endl;
}

void Dijkstra(int start)
{
  priority_queue<pair<int, int>> pq;
  vector<int> dist(n + 1, INF);

  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    for (int i = 0; i < graph[now].size(); i++)
    {
      int next = graph[now][i].first;
      int nextCost = graph[now][i].second;

      if (dist[next] < cost + nextCost)
        continue;
      else
      {
        dist[next] = cost + nextCost;
        pq.push({-dist[next], next});
      }
    }
  }

  friendsDist.push_back(dist);
}

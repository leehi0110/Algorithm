// ProblemNumber || ProblemName : P5944 - Apple Delivery
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

int n, m, start, target_A, target_B;
vector<vector<pair<int, int>>> graph(100001);

vector<int> getDist(int start);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> n >> start >> target_A >> target_B;

  for (int i = 0; i < m; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  vector<int> startDist = getDist(start);
  vector<int> aDist = getDist(target_A);
  vector<int> bDist = getDist(target_B);

  if (startDist[target_A] + aDist[target_B] > startDist[target_B] + bDist[target_A])
  {
    cout << startDist[target_B] + bDist[target_A] << endl;
  }
  else
    cout << startDist[target_A] + aDist[target_B] << endl;
}

vector<int> getDist(int start)
{
  vector<int> dist(n + 1, INF);
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

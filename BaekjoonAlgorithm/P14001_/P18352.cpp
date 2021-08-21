// ProblemNumber || ProblemName : P18352 - 특정 거리의 도시 찾기
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

int n, m, k, x;
vector<int> result;
int dist[300001];
vector<vector<int>> graph(300001);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<pair<int, int>> pq;

  cin >> n >> m >> k >> x;

  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    graph[a].push_back(b);
  }

  dist[x] = 0;
  pq.push({0, x});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    for (int i = 0; i < graph[now].size(); i++)
    {
      int next = graph[now][i];

      if (dist[next] <= cost + 1)
        continue;
      else
      {
        dist[next] = cost + 1;
        pq.push({-dist[next], next});
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (dist[i] == k)
      result.push_back(i);
  }

  if (result.empty())
    cout << "-1\n";
  else
  {
    for (int i = 0; i < result.size(); i++)
    {
      cout << result[i] << endl;
    }
  }
}

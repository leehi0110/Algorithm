// ProblemNumber || ProblemName : P11779 - 최소 비용 구하기 2
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 최단 경로에서 거쳐간 도시들을 구하기 위해 특정 지점에 도달하기 전에 거친 정점을 기록해놓는다.
// -> 기록해놓은 순서를 거꾸로 추적하면 start -> end로 가기위한 최단 경로 내역을 알 수 있다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1e9

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int start, end;

  cin >> n;
  cin >> m;

  vector<vector<pair<int, int>>> graph(n + 1);
  vector<int> dist(n + 1, INF);
  priority_queue<pair<int, int>> pq;
  vector<int> parent(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;

    graph[a].push_back({b, c});
  }

  cin >> start >> end;

  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if (dist[now] < cost)
      continue;

    for (int i = 0; i < graph[now].size(); i++)
    {
      int next = graph[now][i].first;
      int nextCost = graph[now][i].second;

      if (dist[next] > cost + nextCost)
      {
        dist[next] = cost + nextCost;
        pq.push({-dist[next], next});
        parent[next] = now;
      }
    }
  }

  vector<int> temp;
  temp.push_back(end);
  int trace = parent[end];

  while (1)
  {
    temp.push_back(trace);

    if (trace == start)
      break;
    else
    {
      trace = parent[trace];
    }
  }

  cout << dist[end] << endl;                 // 최소 비용
  cout << temp.size() << endl;               // 거쳐간 도시의 개수
  for (int i = temp.size() - 1; i >= 0; i--) // 거쳐간 도시들
  {
    cout << temp[i] << " ";
  }
  cout << endl;
}
// ProblemNumber || ProblemName : P5014 - 스타트링크
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

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int floor, destination, start, up, down;
  cin >> floor >> start >> destination >> up >> down;

  vector<int> dist(floor + 1, INF);
  priority_queue<pair<int, int>> pq;

  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty())
  {
    int cnt = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if (dist[now] < cnt)
      continue;

    if (now + up <= floor && dist[now + up] > cnt + 1)
    {
      dist[now + up] = cnt + 1;
      pq.push({-dist[now + up], now + up});
    }

    if (now - down > 0 && dist[now - down] > cnt + 1)
    {
      dist[now - down] = cnt + 1;
      pq.push({-dist[now - down], now - down});
    }
  }

  if (dist[destination] == INF)
  {
    cout << "use the stairs" << endl;
  }
  else
  {
    cout << dist[destination] << endl;
  }
}

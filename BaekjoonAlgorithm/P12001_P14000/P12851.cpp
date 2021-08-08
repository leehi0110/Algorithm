// ProblemNumber || ProblemName : P12851 - 숨바꼭질 2
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1e9

using namespace std;

int n, k;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  priority_queue<pair<int, int>> pq;
  // 비용 , 좌표
  vector<pair<int, int>> dist(100001, {INF, 0});
  // dist[좌표] = {최단 비용, 가지수}

  cin >> n >> k;

  dist[n] = {0, 1};
  pq.push({0, n});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if (dist[now].first < cost)
      continue;

    for (int i = 0; i < 3; i++)
    {
      int nextTarget;
      if (i == 0)
        nextTarget = now + 1;
      else if (i == 1)
        nextTarget = now - 1;
      else
        nextTarget = now * 2;

      if (nextTarget < 0 || nextTarget > 100000)
        continue;
      else
      {
        if (dist[nextTarget].first > cost + 1)
        {
          dist[nextTarget] = {cost + 1, 1};
          pq.push({-(cost + 1), nextTarget});
        }
        else if (dist[nextTarget].first == cost + 1)
        {
          dist[nextTarget].second++;
          pq.push({-(cost + 1), nextTarget});
        }
        else
        {
          continue;
        }
      }
    }
  }

  cout << dist[k].first << "\n"
       << dist[k].second << endl;
}

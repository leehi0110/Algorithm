// ProblemNumber || ProblemName : P5214 - 환승
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

  int n, k, m;

  cin >> n >> k >> m;
  vector<vector<int>> station(n + m + 1);
  vector<int> dist(n + 1, INF);
  priority_queue<pair<int, int>> pq;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 0; j < k; j++)
    {
      int temp;
      cin >> temp;
      station[temp].push_back(i + n);
      station[i + n].push_back(temp);
    }
  }

  dist[1] = 1;
  pq.push({-1, 1});

  while (!pq.empty())
  {

    int dis = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if (dist[now] < dis)
      continue;

    for (int i = 0; i < station[now].size(); i++)
    {
      vector<int> hyper = station[station[now][i]];
      for (int j = 0; j < hyper.size(); j++)
      {
        if (dist[hyper[j]] > dis + 1)
        {
          dist[hyper[j]] = dis + 1;
          pq.push({-dist[hyper[j]], hyper[j]});
        }
      }
    }
  }

  cout << (dist[n] == INF ? -1 : dist[n]) << endl;
}

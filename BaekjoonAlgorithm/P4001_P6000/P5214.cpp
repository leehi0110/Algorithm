// ProblemNumber || ProblemName : P5214 - 환승
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
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

  vector<set<int>> graph(n + 1);
  vector<int> dist(n + 1, INF);
  queue<int> que;
  vector<bool> visit(n + 1, false);

  for (int i = 0; i < m; i++)
  {
    vector<int> temp;

    for (int j = 0; j < k; j++)
    {
      int station;
      cin >> station;
      temp.push_back(station);
    }

    for (int j = 0; j < temp.size(); j++)
    {
      for (int k = j + 1; k < temp.size(); k++)
      {
        graph[temp[j]].insert(temp[k]);
        graph[temp[k]].insert(temp[j]);
      }
    }
  }

  dist[1] = 1;
  que.push(1);
  // que.push({1, 1});

  while (!que.empty())
  {
    // int now = que.front().first;
    // int drop = que.front().second;
    int now = que.front();

    que.pop();

    // if (dist[now] < drop)
    visit[now] = true;
    //   continue;

    for (auto it = graph[now].begin(); it != graph[now].end(); it++)
    {
      // if (dist[*it] > drop + 1 && !visit[*it])
      if (dist[*it] > dist[now] + 1 && !visit[*it])
      {
        dist[*it] = dist[now] + 1;
        que.push(*it);
        // dist[*it] = drop + 1;
        // que.push({*it, drop + 1});
      }
    }
  }

  if (dist[n] == INF)
    cout << -1 << endl;
  else
    cout << dist[n] << endl;
}

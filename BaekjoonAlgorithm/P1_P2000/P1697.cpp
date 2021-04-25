// ProblemNumber || ProblemName : P1697 - 숨바꼭질

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  vector<int> dist(100001, INF);
  queue<int> que;

  cin >> n >> k;

  if (k < n)
  {
    cout << n - k << endl;
  }
  else if (k == n)
    cout << 0 << endl;
  else
  {
    que.push(n);
    dist[n] = 0;

    while (!que.empty())
    {
      int now = que.front();
      que.pop();

      if (now != 0 && dist[now - 1] > dist[now] + 1)
      {
        dist[now - 1] = dist[now] + 1;
        que.push(now - 1);
      }
      if (now < k && dist[now + 1] > dist[now] + 1)
      {
        dist[now + 1] = dist[now] + 1;
        que.push(now + 1);
      }
      if (now != 0 && now * 2 < 100001 && dist[now * 2] > dist[now] + 1)
      {
        dist[now * 2] = dist[now] + 1;
        que.push(now * 2);
      }
    }
    cout << dist[k] << endl;
  }
}

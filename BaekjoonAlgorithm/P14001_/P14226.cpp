// ProblemNumber || ProblemName : P14226 - 이모티콘
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

int s;
int result = INF;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;

  priority_queue<pair<int, pair<int, int>>> pq;
  vector<vector<int>> table(s + 1, vector<int>(s + 1, INF));

  table[1][0] = 0;
  table[1][1] = 1;

  pq.push({-1, {1, 1}});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int nowLen = pq.top().second.first;
    int clipLen = pq.top().second.second;

    pq.pop();

    if (table[nowLen][clipLen] < cost)
      continue;

    if (nowLen - 1 >= 0 && table[nowLen - 1][clipLen] > cost + 1)
    {
      table[nowLen - 1][clipLen] = cost + 1;
      pq.push({-table[nowLen - 1][clipLen], {nowLen - 1, clipLen}});
    }

    if (nowLen + clipLen <= s && table[nowLen + clipLen][clipLen] > cost + 1)
    {
      table[nowLen + clipLen][clipLen] = cost + 1;
      pq.push({-table[nowLen + clipLen][clipLen], {nowLen + clipLen, clipLen}});
    }

    if (table[nowLen][nowLen] > cost + 1)
    {
      table[nowLen][nowLen] = cost + 1;
      pq.push({-table[nowLen][nowLen], {nowLen, nowLen}});
    }
  }

  for (int i = 0; i <= s; i++)
  {
    if (table[s][i] < result)
      result = table[s][i];
  }

  cout << result << endl;
}

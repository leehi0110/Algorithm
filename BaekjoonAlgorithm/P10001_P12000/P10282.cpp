// ProblemNumber || ProblemName : P10282 - 해킹
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 모든 시간의 합을 구하는 것이 아닌 컴퓨터의 감염이 끝나는데 걸리는 시간(시간의 지속에서 끝 지점)을 구해야한다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

#define INF 1e9

using namespace std;
void dijsktra(int computer, int dependency, int start);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;

  cin >> testCase;

  for (int i = 0; i < testCase; i++)
  {
    int computer, dependency, start;

    cin >> computer >> dependency >> start;

    dijsktra(computer, dependency, start);
  }
}

void dijsktra(int computer, int dependency, int start)
{

  vector<vector<pair<int, int>>> graph(computer + 1);
  priority_queue<pair<int, int>> pq;
  vector<int> infection(computer + 1, INF);
  int resultCom = 0;
  int resultSec = 0;

  for (int j = 0; j < dependency; j++)
  {
    int a, b, s;

    cin >> a >> b >> s;

    graph[b].push_back({a, s});
  }

  infection[start] = 0;
  pq.push({0, start});

  while (!pq.empty())
  {
    int nowSec = -pq.top().first;
    int nowCom = pq.top().second;

    pq.pop();

    if (infection[nowCom] < nowSec)
      continue;

    for (int k = 0; k < graph[nowCom].size(); k++)
    {
      int nextCom = graph[nowCom][k].first;
      int nextSec = graph[nowCom][k].second;

      if (infection[nextCom] > nowSec + nextSec)
      {
        infection[nextCom] = nowSec + nextSec;
        pq.push({-infection[nextCom], nextCom});
      }
    }
  }

  for (int k = 1; k < infection.size(); k++)
  {
    if (infection[k] != INF)
    {
      resultCom++;
      if (infection[k] > resultSec)
        resultSec = infection[k];
    }
  }

  cout << resultCom << " " << resultSec << endl;
}

// ProblemNumber || ProblemName : P13549 - 숨바꼭질 3
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 우선순위큐에 들어갈 수 있는 조건을 정해 문제에서 주어진 메모리 이상 사용하지 않도록 주의한다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9

using namespace std;

int table[100001];
int n, k;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  priority_queue<pair<int, int>> pq;

  cin >> n >> k;

  for (int i = 0; i < 100001; i++)
  {
    table[i] = INF;
  }

  table[n] = 0;
  pq.push({0, n});

  while (!pq.empty() && table[k] == INF)
  {
    int dist = -pq.top().first;
    int nowX = pq.top().second;

    pq.pop();

    if (table[nowX] < dist)
      continue;

    table[nowX] = dist;

    if (nowX * 2 <= 100000 && table[nowX * 2] > dist)
      pq.push({-(dist), nowX * 2});
    if (nowX + 1 <= 100000 && table[nowX + 1] > dist + 1)
      pq.push({-(dist + 1), nowX + 1});
    if (nowX - 1 >= 0 && table[nowX - 1] > dist + 1)
      pq.push({-(dist + 1), nowX - 1});
  }

  cout << table[k] << endl;
}

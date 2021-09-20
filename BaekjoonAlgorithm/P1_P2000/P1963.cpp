// ProblemNumber || ProblemName : P1963 - 소수 경로
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
vector<bool> primes(100000, true);

void solve();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;
  cin >> testCase;

  primes[0] = false;
  primes[1] = false;

  for (int i = 2; i < 10000; i++)
  {
    if (primes[i])
    {
      for (int j = i * 2; j < 10000; j += i)
        primes[j] = false;
    }
  }

  for (int i = 0; i < testCase; i++)
  {
    solve();
  }
}

void solve()
{
  int start, end;
  priority_queue<pair<int, int>> pq;
  vector<int> table(10000, INF);

  cin >> start >> end;

  table[start] = 0;
  pq.push({0, start});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if (table[now] < cost)
      continue;

    for (int i = 0; i < 4; i++)
    {
      string nowStr = to_string(now);

      for (int j = 0; j < 10; j++)
      {
        if (i == 0 && j == 0)
          continue;

        string tempStr = nowStr;
        tempStr[i] = j + '0';
        int tempNum = stoi(tempStr);

        if (primes[tempNum] && table[tempNum] > cost + 1)
        {
          table[tempNum] = cost + 1;
          pq.push({-table[tempNum], tempNum});
        }
      }
    }
  }

  cout << table[end] << endl;
}

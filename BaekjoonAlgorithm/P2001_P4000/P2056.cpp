// ProblemNumber || ProblemName : P2056 - 작업
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int result = 0;
int in[10001];                      // 선행되어야 할 작업의 개수
int workTime[10001];                // 작업에 필요한 시간
int maxTime[10001];                 // 선행 작업을 거쳐 내 작업이 끝나는 시간
vector<vector<int>> process(10001); // 내 뒤에 수행할 작업의 번호

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  queue<int> que;

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    int workCnt;

    cin >> workTime[i] >> in[i];

    for (int j = 0; j < in[i]; j++)
    {
      int temp;

      cin >> temp;

      process[temp].push_back(i);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (in[i] == 0)
    {
      que.push(i);
    }
  }

  while (!que.empty())
  {
    int nowWork = que.front();
    que.pop();

    maxTime[nowWork] += workTime[nowWork];
    if (result < maxTime[nowWork])
      result = maxTime[nowWork];

    for (int i = 0; i < process[nowWork].size(); i++)
    {
      int nextWork = process[nowWork][i];

      maxTime[nextWork] = max(maxTime[nextWork], maxTime[nowWork]);
      in[nextWork]--;

      if (in[nextWork] == 0)
        que.push(nextWork);
    }
  }

  cout << result << endl;
}

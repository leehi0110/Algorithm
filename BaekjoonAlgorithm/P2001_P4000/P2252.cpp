// ProblemNumber || ProblemName : P2252 - 줄 세우기
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 문제가 요구하는 알고리즘이 뭔지 생각하기
// -> 우선적으로 푼 뒤에 더 쉬운 로직이 있는지 생각

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  vector<int> input(n + 1, 0);
  vector<vector<int>> graph(n + 1);
  queue<int> que;

  for (int i = 0; i < m; i++)
  {
    int a, b;

    cin >> a >> b;

    graph[a].push_back(b); // a보다 큰사람 벡터
    input[b]++;            // 나보다 작은 사람은 명 수
  }

  for (int i = 1; i <= n; i++)
  {
    if (input[i] == 0)
    {
      que.push(i);
    }
  }

  while (!que.empty())
  {
    int zeroInput = que.front();
    que.pop();

    for (int i = 0; i < graph[zeroInput].size(); i++)
    {
      int nextInput = graph[zeroInput][i];
      input[nextInput]--;

      if (input[nextInput] == 0)
      {
        que.push(nextInput);
      }
    }

    cout << zeroInput << " ";
  }
  cout << endl;
}
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

  int verNum, edgeNum;
  vector<vector<int>> graph(verNum + 1);
  vector<int> indegree(verNum + 1, 0);
  vector<int> result;
  queue<int> que;

  cin >> verNum >> edgeNum;

  for (int i = 0; i < edgeNum; i++)
  {
    int a, b;
    cin >> a >> b;

    graph[a].push_back(b);
    indegree[b]++;
  }

  for (int i = 1; i <= verNum; i++)
  {
    if (indegree[i] == 0)
    {
      que.push(i);
    }
  }

  while (!que.empty())
  {
    int now = que.front();
    que.pop();

    result.push_back(now);

    for (int i = 0; i < graph[now].size(); i++)
    {
      int next = graph[now][i];
      indegree[next]--;

      if (indegree[next] == 0)
      {
        que.push(next);
      }
    }
  }

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;
}

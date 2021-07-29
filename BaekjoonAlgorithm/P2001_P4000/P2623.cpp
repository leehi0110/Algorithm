// ProblemNumber || ProblemName : P2623 - 음악프로그램
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

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
  vector<int> result;
  queue<int> que;

  cin >> n >> m;

  vector<int> in(n + 1, 0);
  vector<vector<int>> tp(n + 1);

  for (int i = 0; i < m; i++)
  {
    int temp;
    cin >> temp;
    vector<int> vec(temp);

    for (int j = 0; j < temp; j++)
    {
      cin >> vec[j];
    }

    for (int j = 1; j < vec.size(); j++)
    {
      in[vec[j]]++;
      tp[vec[j - 1]].push_back(vec[j]);
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
    int now = que.front();
    que.pop();

    result.push_back(now);

    for (int i = 0; i < tp[now].size(); i++)
    {
      int next = tp[now][i];

      in[next]--;
      if (in[next] == 0)
      {
        que.push(next);
      }
    }
  }

  if (result.size() != n)
    cout << 0 << endl;
  else
  {
    for (int i = 0; i < result.size(); i++)
    {
      cout << result[i] << endl;
    }
  }
}
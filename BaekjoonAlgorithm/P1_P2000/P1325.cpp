// ProblemNumber || ProblemName : 1325 - 효율적인 해킹

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
bool visited[100001];
vector<int> graph[100001];

void DFS(int idx)
{
  visited[idx] = true;

  for (int i = 0; i < graph[idx].size(); i++)
  {
    int nextIdx = graph[idx][i];

    if (!visited[nextIdx])
    {
      cnt++;
      DFS(nextIdx);
    }
  }
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    graph[b].push_back(a);
  }

  int maxCnt = 0;
  vector<int> com;

  for (int i = 1; i < n + 1; i++)
  {
    memset(visited, false, sizeof(visited));
    cnt = 0;

    DFS(i);

    if (cnt > maxCnt)
    {
      com.clear();
      com.push_back(i);
      maxCnt = cnt;
    }
    else if (cnt == maxCnt)
    {
      com.push_back(i);
    }
  }

  sort(com.begin(), com.end());

  for (int i = 0; i < com.size(); i++)
  {
    cout << com[i] << " ";
  }
  cout << endl;
}
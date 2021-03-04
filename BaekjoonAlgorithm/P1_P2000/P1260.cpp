// ProblemNumber || ProblemName : DFS와 BFS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
void DFS(vector<vector<int>> graph, vector<bool> &visit, int start);
void BFS(vector<vector<int>> graph, vector<bool> &visit, int start);

int main()
{
  int n, m, v;

  cin >> n >> m >> v;

  vector<vector<int>> graph(n + 1, vector<int>());
  vector<bool> visit(n + 1, false);

  for (int i = 0; i < m; i++)
  {
    int start, end;
    cin >> start >> end;

    graph[start].push_back(end);
    graph[end].push_back(start);
  }

  for (int i = 0; i < graph.size(); i++)
  {
    sort(graph[i].begin(), graph[i].end(), less<int>());
  }

  DFS(graph, visit, v);
  cout << endl;

  fill(visit.begin(), visit.end(), false);
  BFS(graph, visit, v);
  cout << endl;
}

void BFS(vector<vector<int>> graph, vector<bool> &visit, int start)
{
  queue<int> que;

  que.push(start);

  while (!que.empty())
  {
    int now = que.front();
    que.pop();

    if (!visit[now])
    {
      cout << now << " ";
      visit[now] = true;
      for (int i = 0; i < graph[now].size(); i++)
      {
        que.push(graph[now][i]);
      }
    }
  }
}

void DFS(vector<vector<int>> graph, vector<bool> &visit, int start)
{
  visit[start] = true;
  cout << start << " ";

  for (auto next : graph[start])
  {
    if (visit[next] == false)
      DFS(graph, visit, next);
  }
}
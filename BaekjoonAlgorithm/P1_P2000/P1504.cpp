// ProblemNumber || ProblemName : 1504 - 특정한 최단 경로

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1e9

using namespace std;

int N, E;
int firstVertex, secondVertex;

void dijkstra(vector<vector<pair<int, int>>> graph, int start, int end, int &result);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> E;

  vector<vector<pair<int, int>>> graph(N + 1);
  vector<vector<int>> table(N + 1, vector<int>(N + 1, INF));

  for (int i = 0; i < table.size(); i++)
  {
    for (int j = 0l; j < table.size(); j++)
    {
      if (i == j)
        table[i][j] = 0;
    }
  }

  for (int i = 0; i < E; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});

    table[a][b] = c;
    table[b][a] = c;
  }

  for (int k = 1; k < N + 1; k++)
  {
    for (int i = 1; i < N + 1; i++)
    {
      for (int j = 1; j < N + 1; j++)
      {
        table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
        table[j][i] = table[i][j];
      }
    }
  }

  cin >> firstVertex >> secondVertex;

  int first_result = table[1][firstVertex] + table[firstVertex][secondVertex] + table[secondVertex][N];
  int second_result = table[1][secondVertex] + table[secondVertex][firstVertex] + table[firstVertex][N];

  if (first_result < second_result)
  {
    if (first_result == INF)
      cout << -1 << endl;
    else
      cout << first_result << endl;
  }
  else
  {
    if (second_result == INF)
      cout << -1 << endl;
    else
      cout << second_result << endl;
  }
}
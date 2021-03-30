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

  for (int i = 0; i < E; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
}
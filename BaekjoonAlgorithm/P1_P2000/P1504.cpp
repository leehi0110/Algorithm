// ProblemNumber || ProblemName : P1504 - 특정한 최단경로

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

// long long INF = 987654321;
long long table[801][801];
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, e;
  int firstStop, secondStop;

  cin >> n >> e;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        table[i][j] = 0;
      else
        table[i][j] = INF;
    }
  }

  for (int i = 0; i < e; i++)
  {
    int start, end, cost;

    cin >> start >> end >> cost;

    table[start][end] = cost;
    table[end][start] = cost;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (i == j)
          continue;
        table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
      }
    }
  }

  cin >> firstStop >> secondStop;

  long long result = min(table[1][firstStop] + table[firstStop][secondStop] + table[secondStop][n], table[1][secondStop] + table[secondStop][firstStop] + table[firstStop][n]);

  if (result >= INF)
    cout << -1 << endl;
  else
    cout << result << endl;
}

// int vertexNum, edgeNum;
// int firstStop, secondStop;
// int PriorityQueDijkstra(vector<vector<pair<int, int>>> graph, int start, int end);

// int main()
// {
//   ios_base ::sync_with_stdio(false);
//   cin.tie(NULL);

//   cin >> vertexNum >> edgeNum;

//   vector<vector<pair<int, int>>> graph(vertexNum + 1);

//   for (int i = 0; i < edgeNum; i++)
//   {
//     int start, end, cost;

//     cin >> start >> end >> cost;

//     graph[start].push_back({end, cost});
//     graph[end].push_back({start, cost});

//   } // 간선정보 입력

//   cin >> firstStop >> secondStop; // 경유지 입력

//   int firstResult = PriorityQueDijkstra(graph, 1, firstStop) + PriorityQueDijkstra(graph, firstStop, secondStop) + PriorityQueDijkstra(graph, secondStop, vertexNum);

//   int secondResult = PriorityQueDijkstra(graph, 1, secondStop) + PriorityQueDijkstra(graph, secondStop, firstStop) + PriorityQueDijkstra(graph, firstStop, vertexNum);

//   if (firstResult == INF && secondResult == INF)
//     cout << -1 << endl;
//   else
//   {
//     if (firstResult > secondResult)
//       cout << secondResult << endl;
//     else
//       cout << firstResult << endl;
//   }
// }

// int PriorityQueDijkstra(vector<vector<pair<int, int>>> graph, int start, int end)
// {
//   vector<int> distance(vertexNum + 1, INF);
//   priority_queue<pair<int, int>> pq;

//   pq.push({0, start});
//   distance[start] = 0;

//   while (!pq.empty())
//   {

//     int dis = -pq.top().first;
//     int des = pq.top().second;

//     pq.pop();

//     if (distance[des] < dis)
//       continue;

//     for (int i = 0; i < graph[des].size(); i++)
//     {
//       int cost = dis + graph[des][i].second;

//       if (cost < distance[graph[des][i].first])
//       {
//         distance[graph[des][i].first] = cost;
//         pq.push({-cost, graph[des][i].first});
//       }
//     }
//   }

//   return distance[end];
// }

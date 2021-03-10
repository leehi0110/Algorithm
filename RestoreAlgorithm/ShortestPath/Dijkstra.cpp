// ProblemNumber || ProblemName : 다익스트라 알고리즘

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int get_smallest_node(vector<bool> visit, vector<int> distance);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, s;

  cin >> n >> m;
  cin >> s;

  vector<bool> visit(n + 1, false);
  vector<int> distance(n + 1, 99999);
  vector<vector<pair<int, int>>> graph(n + 1);

  for (int i = 0; i < m; i++)
  {
    int start, end, cost;

    cin >> start >> end >> cost;

    graph[start].push_back({end, cost});
  }

  visit[s] = true;
  distance[s] = 0;

  for (int i = 0; i < graph[s].size(); i++)
  {
    int des = graph[s][i].first;
    int cost = graph[s][i].second;

    distance[des] = cost;
  }

  for (int i = 1; i < n; i++)
  {
    int minIdx = get_smallest_node(visit, distance);
    visit[minIdx] = true;

    for (int j = 0; j < graph[minIdx].size(); j++)
    {
      int des = graph[minIdx][j].first;
      int graphCost = graph[minIdx][j].second;

      int cost = distance[minIdx] + graphCost;

      if (distance[des] > cost)
      {
        distance[des] = cost;
      }
    }
  }

  for (int i = 1; i < distance.size(); i++)
  {
    cout << distance[i] << endl;
  }
}

int get_smallest_node(vector<bool> visit, vector<int> distance)
{
  int minEle = 99999;
  int minIdx = 0;

  for (int i = 1; i < distance.size(); i++)
  {
    if (!visit[i] && distance[i] < minEle)
    {
      minIdx = i;
      minEle = distance[i];
    }
  }

  return minIdx;
}

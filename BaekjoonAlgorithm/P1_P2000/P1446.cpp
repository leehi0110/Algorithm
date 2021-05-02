// ProblemNumber || ProblemName : P1446 - 지름길

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, D;

<<<<<<< Updated upstream
  vector<int> distance(d + 1, 0);
  vector<vector<pair<int, int>>> graph(d + 1);

  for (int i = 0; i <= d; i++)
=======
  cin >> N >> D;
  vector<vector<int>> roads;
  vector<int> distance(D + 1, 0);

  for (int i = 0; i < D + 1; i++)
>>>>>>> Stashed changes
  {
    distance[i] = i;
  }

  for (int i = 0; i < N; i++)
  {
<<<<<<< Updated upstream
    int start, end, cost;

    cin >> start >> end >> cost;

    if (end - start <= cost)
      continue;
    else if (end > d)
      continue;
    else
    {
      graph[start].push_back({end, cost});
    }
  }

  for (int i = 0; i <= d; i++)
  {
    int before;

    if (i == 0)
      before = -1;
    else
      before = distance[i - 1];

    distance[i] = min(before + 1, distance[i]);

    if (!graph[i].empty())
    {
      for (int j = 0; j < graph[i].size(); j++)
      {
        int next = graph[i][j].first;
        int nextCost = graph[i][j].second;

        if (distance[i] + nextCost < distance[next])
        {
          distance[next] = distance[i] + nextCost;
=======
    int start, end, dist;

    cin >> start >> end >> dist;

    if (end - start <= dist || end > D)
      continue;
    else
    {
      roads.push_back({start, end, dist});
    }
  }

  for (int i = 0; i < roads.size(); i++)
  {
    int start = roads[i][0], end = roads[i][1];
    int cost = distance[start] + roads[i][2];

    if (distance[end] > cost)
    {
      distance[end] = cost;
      int addDistance = 1;
      for (int j = end + 1; j < D + 1; j++)
      {
        if (distance[j] < distance[end] + addDistance)
          break;
        else
        {
          distance[j] = distance[end] + addDistance++;
>>>>>>> Stashed changes
        }
      }
    }
  }

<<<<<<< Updated upstream
  cout << distance[d] << endl;
=======
  cout << distance[D] << endl;
>>>>>>> Stashed changes
}
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

  int n, d;

  cin >> n >> d;

  vector<int> distance(d + 1, 0);
  vector<vector<pair<int, int>>> graph(d + 1);

  for (int i = 0; i <= d; i++)
  {
    distance[i] = i;
  }

  for (int i = 0; i < n; i++)
  {
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
        }
      }
    }
  }

  cout << distance[d] << endl;
}
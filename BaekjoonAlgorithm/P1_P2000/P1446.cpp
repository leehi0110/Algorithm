// ProblemNumber || ProblemName : P1446 - 지름길

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define INF 1e9

using namespace std;
bool comp(vector<int> a, vector<int> b);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, d;

  cin >> n >> d;

  vector<vector<int>> arr;
  vector<int> dist(d + 1);

  for (int i = 1; i < dist.size(); i++)
  {
    dist[i] = i;
  }

  for (int i = 0; i < n; i++)
  {
    int start, end, cost;
    cin >> start >> end >> cost;

    if (end > d || end - start <= cost)
      continue;
    else
      arr.push_back({start, end, cost});
  }

  for (int i = 0; i < arr.size(); i++)
  {
    int start = arr[i][0], end = arr[i][1], cost = arr[i][2];

    if (dist[end] > dist[start] + cost)
    {
      int k = 0;
      for (int j = end; j < dist.size(); j++)
      {
        dist[j] = k + dist[start] + cost;
        k++;
      }
    }
  }

  cout << dist[d] << endl;
}

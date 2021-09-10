// ProblemNumber || ProblemName : P15686 - 치킨 배달
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 조합에 대해 생각해야된다 (1,2,3) 과 (3,1,2)는 같은것으로 판별한다
// -> 시간을 최대한 줄일 수 있는 방법에 대해 생각해야된다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9
using namespace std;

int n, m;
int result = INF;
int map[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<bool> visited(51, false);
int getDist(pair<int, int> a, pair<int, int> b);
void DFS(int idx, int selected);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
      if (map[i][j] == 1)
        house.push_back({i, j});
      else if (map[i][j] == 2)
        chicken.push_back({i, j});
    }
  }

  DFS(0, 0);
  cout << result << endl;
}

void DFS(int idx, int selected)
{
  if (selected == m)
  {

    int tempDist = 0;
    for (int i = 0; i < house.size(); i++)
    {

      int dist = INF;
      for (int j = 0; j < chicken.size(); j++)
      {
        if (visited[j])
        {
          dist = min(dist, getDist(house[i], chicken[j]));
        }
      }
      tempDist += dist;
    }
    result = min(result, tempDist);
    return;
  }

  if (idx == chicken.size())
    return;

  visited[idx] = true;
  DFS(idx + 1, selected + 1);

  visited[idx] = false;
  DFS(idx + 1, selected);
}

int getDist(pair<int, int> a, pair<int, int> b)
{
  return abs(a.first - b.first) + abs(a.second - b.second);
}

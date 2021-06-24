// ProblemNumber || ProblemName : P10026 - 적록색약
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void bfs(vector<vector<string>> &map, int y, int x, int area, string color);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  vector<vector<string>> map(n);
  vector<vector<string>> simpleMap(n);

  for (int i = 0; i < n; i++)
  {
    string temp;

    cin >> temp;

    for (int j = 0; j < temp.length(); j++)
    {
      string tmp = temp.substr(j, 1);

      map[i].push_back(tmp);

      if (tmp == "G")
        simpleMap[i].push_back("R");
      else
        simpleMap[i].push_back(tmp);
    }
  }

  int area = 0;
  int simpleArea = 0;

  for (int i = 0; i < map.size(); i++)
  {
    for (int j = 0; j < map[i].size(); j++)
    {
      if (map[i][j] == "R" || map[i][j] == "G" || map[i][j] == "B")
      {
        area++;
        bfs(map, i, j, area, map[i][j]);
      }

      if (simpleMap[i][j] == "R" || simpleMap[i][j] == "B")
      {
        simpleArea++;
        bfs(simpleMap, i, j, area, simpleMap[i][j]);
      }
    }
  }

  cout << area << " " << simpleArea << endl;
}

void bfs(vector<vector<string>> &map, int y, int x, int area, string color)
{

  map[y][x] = to_string(area);

  for (int i = 0; i < 4; i++)
  {
    int moveX = x + dx[i];
    int moveY = y + dy[i];

    if (moveX < 0 || moveY < 0 || moveX >= map[0].size() || moveY >= map.size() || map[moveY][moveX] != color)
      continue;
    else
    {
      bfs(map, moveY, moveX, area, color);
    }
  }
}

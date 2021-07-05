// ProblemNumber || ProblemName : P1520 - 내리막길
// 하면서 좀 더 깊게 생각하게 된 것들
// -> '0'이 지나온 길 중에 갈 수 있는 길이 없는 것인지, 아직 한번도 지나가보지 않는 길인지 알 수 없으니 제 3의 수를 둬야한다
// -> '-1'은 한번도 방문하지 않은 경우, '0'은 방문했지만 경로가 없는 경우, 그 외는 방문해서 갈 수 있는 경로를 의미

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
void DFS(int x, int y);

int n, m;
int map[501][501];
int table[501][501];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> n;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> map[i][j];
      table[i][j] = -1;
    }
  }

  DFS(1, 1);

  cout << table[1][1] << endl;
}

void DFS(int x, int y)
{
  // -1 아직 방문하지 않은 것
  // 0 방문했는데 다음에서 갈 수 있는 경로가 없는 것
  // 이외의 숫자 방문한 뒤 갈 수 있는 경로의 수

  if (table[y][x] == -1)
    table[y][x] = 0;
  else
  {
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    int moveX = x + dx[i];
    int moveY = y + dy[i];

    if (moveX < 0 || moveY < 0 || moveX > n || moveY > m || map[y][x] <= map[moveY][moveX])
      continue;

    if (moveX == n && moveY == m)
    {
      table[y][x] = table[y][x] + 1;
    }
    else
    {
      DFS(moveX, moveY);
      table[y][x] = table[y][x] + table[moveY][moveX];
    }
  }
}
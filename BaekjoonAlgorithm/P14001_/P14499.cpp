// ProblemNumber || ProblemName : P14499 - 주사위 굴리기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m; // 지도의 크기
int x, y; // 초기 위치
int k;
int map[21][21];

int dice[6] = {0, 0, 0, 0, 0, 0};
// top, bottom, up, down, left, right;

void setDice(int direction);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> x >> y >> k;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < k; i++)
  {
    int cmd;
    cin >> cmd;

    setDice(cmd);
  }
}

void setDice(int direction)
{
  int top = dice[0];    // 윗 면
  int bottom = dice[1]; // 아랫 면
  int up = dice[2];     // 북쪽 면
  int down = dice[3];   // 남쪽 면
  int left = dice[4];   // 왼쪽 면
  int right = dice[5];  // 오른쪽 면

  if (direction == 1)
  { // 동

    if (y + 1 >= m)
      return;

    y++;

    dice[0] = left;
    dice[1] = right;
    dice[4] = bottom;
    dice[5] = top;

    // top -> right;
    // right -> bottom
    // bottom -> left
    // left -> top
  }
  else if (direction == 2)
  { // 서

    if (y - 1 < 0)
      return;

    y--;

    dice[4] = top;
    dice[1] = left;
    dice[5] = bottom;
    dice[0] = right;

    // top -> left
    // left -> bottom
    // bottom -> right
    // right -> top;
  }
  else if (direction == 3)
  { // 북
    if (x - 1 < 0)
      return;

    x--;

    dice[2] = top;
    dice[1] = up;
    dice[3] = bottom;
    dice[0] = down;
    // top -> up
    // up -> bottom
    // bottom -> down
    // down -> top
  }
  else
  { // 남

    if (x + 1 >= n)
      return;

    x++;

    dice[3] = top;
    dice[0] = up;
    dice[2] = bottom;
    dice[1] = down;

    // top -> down
    // up -> top
    // bottom -> up
    // down -> bottom
  }

  if (map[x][y] == 0)
  {
    map[x][y] = dice[1];
  }
  else
  {
    dice[1] = map[x][y];
    map[x][y] = 0;
  }

  cout << dice[0] << endl;
}
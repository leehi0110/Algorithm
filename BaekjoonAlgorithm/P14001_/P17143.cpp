// ProblemNumber || ProblemName : P17143 - 낚시왕
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int n, m, sharkNum;
int result = 0;
int map[101][101];
vector<vector<int>> sharkInfo;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

// d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다

void moveShark();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> sharkNum;

  for(int i=0;i<=n;i++) {
    for(int j=0;j<=m;j++) {
      map[i][j] = -1;
    }
  }

  for(int i=0;i<sharkNum;i++) {
    int x, y, s, d, z;

    cin >> x >> y >> s >> d >> z;
    map[x][y] = i;
    sharkInfo.push_back({x,y,s,d,z});
  }

  for(int i=1;i<=m;i++) {

    for(int j=1;j<=n;j++) {
      if(map[j][i] == -1) continue;
      else {
        int getShark = map[j][i];
        result += sharkInfo[getShark][4]; // 가장 가까운 상어를 잡는다
        sharkInfo[getShark] = {0,0,0,0,0};
        map[j][i] = -1;
        break;
      }
    }
    moveShark();
  }

  cout << result << endl;
}

void moveShark()
{
  int moveMap[n+1][m+1];

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      moveMap[i][j] = -1;
    }
  }

  for(int i=0;i<sharkInfo.size();i++) {
    int x = sharkInfo[i][0]; // x 좌표
    int y = sharkInfo[i][1]; // y 좌표
    int speed = sharkInfo[i][2]; // 속도
    int direction = sharkInfo[i][3]; // 방향
    int size = sharkInfo[i][4]; // 크기

    if(x == 0 && y == 0) continue;
    else {

      for(int j=0;j<speed;j++) {
        int moveX = x + dx[direction];
        int moveY = y + dy[direction];

        if(moveX <= 0 || moveY <= 0 || moveX > n || moveY > m) {
          if(direction == 1) direction = 2;
          else if(direction == 2) direction = 1;
          else if(direction == 3) direction = 4;
          else direction = 3;

          j--;
        } else {
          x = moveX;
          y = moveY;
        }
      } // 이동

      sharkInfo[i] = {x,y,speed, direction, size};

      if(moveMap[x][y] == -1) {
        moveMap[x][y] = i;
      } else {
        
        if(sharkInfo[moveMap[x][y]][4] > size) {
          sharkInfo[i][0] = 0;
          sharkInfo[i][1] = 0;
        } else {
          sharkInfo[moveMap[x][y]][0] = 0;
          sharkInfo[moveMap[x][y]][1] = 0;
          moveMap[x][y] = i;
        }
      } // 잡아먹기 실행
    }
  }

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      if(moveMap[i][j] == -1) map[i][j] = -1;
      else map[i][j] = moveMap[i][j];
    }
  }
}
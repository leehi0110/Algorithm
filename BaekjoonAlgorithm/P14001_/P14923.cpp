// ProblemNumber || ProblemName : P14923 - 미로 탈출
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

int n, m;
int map[1001][1001];
int startX, startY;
int endX, endY;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool visit[1001][1001][2];

int bfs();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  cin >> startX >> startY;
  cin >> endX >> endY;

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      cin >> map[i][j];
    }
  }

  int returnVal = bfs();

  cout << returnVal << endl;
}

int bfs() {

  queue<pair<pair<int,int>,pair<int,int>>> que;
  visit[startX][startY][0] = true;
  que.push({{startX, startY}, {0, 0}});

  while(!que.empty()) {
    int x = que.front().first.first;
    int y = que.front().first.second;
    int block = que.front().second.first;
    int cost = que.front().second.second;

    que.pop();

    for(int i=0;i<4;i++) {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if(moveX == endX && moveY == endY) return cost + 1;

      if(moveX <= 0 || moveY <= 0 || moveX > n || moveY > m) continue;
      else {
        if(map[moveX][moveY] == 1 && block == 0 && !visit[moveX][moveY][1]) {
          que.push({{moveX,moveY}, {1, cost+1}});
          visit[moveX][moveY][1] = true;
        } else if(map[moveX][moveY] == 0 && !visit[moveX][moveY][block]) {
          que.push({{moveX,moveY}, {block, cost + 1}});
          visit[moveX][moveY][block] = true;
        }
      }
    }
  }

  return -1;
  
}
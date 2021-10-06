// ProblemNumber || ProblemName : P14442 - 벽 부수고 이동하기 2
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

int n, m, k;
bool visit[1001][1001][11];
int map[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int BFS();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;

  for(int i=0;i<n;i++) {
    string path;

    cin >> path;

    for(int j=0;j<path.length();j++) {
      map[i][j] = path[j] - '0';
    }
  }

  int result = BFS();

  cout << result << endl;
}

int BFS()
{

  queue<pair<pair<int,int>,pair<int,int>>> que;
  
  que.push({{0,0},{0,1}});
  visit[0][0][0] = true;

  while(!que.empty()) {
    int x = que.front().first.first;
    int y = que.front().first.second;
    int b = que.front().second.first;
    int dist = que.front().second.second;

    que.pop();

    if(x == n-1 && y == m-1) return dist;

    for(int i=0;i<4;i++) {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if(moveX >= 0 && moveY >= 0 && moveX < n && moveY < m) {
        if(map[moveX][moveY] == 1 && b < k && !visit[moveX][moveY][b+1]) {
          que.push({{moveX,moveY}, {b+1, dist+1}});
          visit[moveX][moveY][b+1] = true;
        } else if(map[moveX][moveY] == 0 && !visit[moveX][moveY][b]) {
          que.push({{moveX,moveY},{b,dist+1}});
          visit[moveX][moveY][b] = true;
        }
      }
    }
  }

  return -1;
}
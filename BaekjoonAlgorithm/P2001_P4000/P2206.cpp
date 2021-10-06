// ProblemNumber || ProblemName : P2206 - 벽 부수고 이동하기
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 조건을 나눠서 생각
// -> 다음이 벽일 경우 -> 벽을 깰 수 있으면 깨고 전진, 그렇지 않으면 멈춘다
// -> 다음이 빈공간일 경우 -> 현재 상태와 비교해서 왔던 길이면 가지 않고, 오지 않았던 길이면 간다

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
bool visit[1001][1001][2];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int BFS();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for(int i=0;i<n;i++) {
    string row;
    cin >> row;

    for(int j=0;j<row.length();j++) {
      map[i][j] = row[j] - '0';
    }
  }

  int result = BFS();

  cout << result <<endl;
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
    int cnt = que.front().second.second;

    que.pop();

    if(x == n-1 && y == m-1) return cnt;

    for(int i=0;i<4;i++) {
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if(moveX >= 0 && moveY >= 0 && moveX < n && moveY < m) {
        if(map[moveX][moveY] == 1 && b == 0) {
          visit[moveX][moveY][b+1] = true;
          que.push({{moveX,moveY}, {b + 1, cnt + 1}});
        } else if(map[moveX][moveY] == 0 && !visit[moveX][moveY][b]) {
          visit[moveX][moveY][b] = true;
          que.push({{moveX,moveY}, {b, cnt+1}});
        }
      }
    }
  }
  return -1;
}
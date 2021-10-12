// ProblemNumber || ProblemName : P11909 - 배열 탈출
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#define INF 1e9

using namespace std;

int n;
int map[2223][2223];
int dp[2223][2223];
int dx[2] = {1,0};
int dy[2] = {0,1};

int search(int x, int y);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      cin >> map[i][j];
      dp[i][j] = INF;
    }
  }

  // dijkstra();

  cout << search(1,1) << endl;
}

int search(int x, int y)
{
  if(x == n && y == n) return 0;
  else if(dp[x][y] != INF) return dp[x][y];

  int result = INF;

  for(int i=0;i<2;i++) {
    int moveX = x + dx[i];
    int moveY = y + dy[i];

    if(moveX <= 0 || moveY <= 0 || moveX > n || moveY > n) continue;
    
    if(map[x][y] > map[moveX][moveY]) result = min(result, search(moveX, moveY));
    else {
      int gap = map[moveX][moveY] - map[x][y] + 1;
      result = min(result, search(moveX,moveY) + gap);
    }
  }

  dp[x][y] = result;
  return dp[x][y];
}

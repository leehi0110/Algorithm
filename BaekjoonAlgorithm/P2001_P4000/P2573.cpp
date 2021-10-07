// ProblemNumber || ProblemName : P2573 - 빙산
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
int result = 0;
int map[301][301];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

void meltFunc();
int isSeparate();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin >> map[i][j];
    }
  }

  while(1) {
    int separateResult = isSeparate();

    if(separateResult == 1) meltFunc();
    else if(separateResult == 0) {
      result = 0;
      break;
    } else break;
  }

  cout << result << endl;
}

int isSeparate()
{
  int blockCnt = 0;
  vector<vector<int>> newMap(n, vector<int>(m,0));
  queue<pair<pair<int,int>, int>> que;

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if(map[i][j] != 0 && newMap[i][j] == 0) {
        newMap[i][j] = ++blockCnt;
        que.push({{i,j}, blockCnt});
      }

      while(!que.empty()) {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int block = que.front().second;

        que.pop();

        for(int k=0;k<4;k++) {
          int moveX = x + dx[k];
          int moveY = y + dy[k];

          if(moveX >= 0 && moveY >= 0 && moveX < n && moveY < m && map[moveX][moveY] != 0 && newMap[moveX][moveY] == 0) {
            newMap[moveX][moveY] = blockCnt;
            que.push({{moveX,moveY}, blockCnt});
          }
        }
      }
    }
  }

  return blockCnt;
}

void meltFunc()
{
  queue<pair<pair<int,int>,int>> que;

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      int meltCnt = 0;

      for(int k=0;k<4;k++) {
        int moveX = i + dx[k];
        int moveY = j + dy[k];

        if(moveX >= 0 && moveY >=0 && moveX < n && moveY < m && map[moveX][moveY] == 0) meltCnt++;
      }
      if(meltCnt != 0) que.push({{i,j}, meltCnt});
    }
  }

  while(!que.empty()) {
    int x = que.front().first.first;
    int y = que.front().first.second;
    int meltCnt = que.front().second;

    que.pop();

    if(map[x][y] >= meltCnt) map[x][y] -= meltCnt;
    else map[x][y] = 0;
  }

  result ++;
}
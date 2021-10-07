// ProblemNumber || ProblemName : P16234 - 인구 이동
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int n, l, r;
int result = 0;
vector<vector<int>> map(51, vector<int>(51, 0));
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool moveFunc();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> l >> r;

  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> map[i][j];
    }
  }

  while(1) {
    if(!moveFunc()) break;
  }

  cout << result << endl;
}

bool moveFunc()
{
  int areaCnt = 0;
  vector<vector<int>> newMap(51, vector<int>(51, 0));
  vector<pair<int,int>> areaInfo(2501, {0,0});
  queue<pair<pair<int,int>,int>> que;

  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      if(newMap[i][j] == 0) {
        newMap[i][j] = ++areaCnt;
        areaInfo[areaCnt].first += map[i][j];
        areaInfo[areaCnt].second ++;
        que.push({{i,j}, areaCnt});
      }

      while(!que.empty()) {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int areaNum = que.front().second;

        que.pop();

        for(int k=0;k<4;k++) {
          int moveX = x + dx[k];
          int moveY = y + dy[k];

          if(moveX >= 0 && moveY >= 0 && moveX < n && moveY < n && newMap[moveX][moveY] == 0 && abs(map[x][y] - map[moveX][moveY]) >= l && abs(map[x][y] - map[moveX][moveY]) <= r) {
            newMap[moveX][moveY] = areaNum;
            areaInfo[areaNum].first += map[moveX][moveY];
            areaInfo[areaNum].second ++;
            que.push({{moveX, moveY}, areaNum});
          }
        }
      }
    }
  }

  if(areaCnt < n*n) {
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        map[i][j] = (areaInfo[newMap[i][j]].first)/(areaInfo[newMap[i][j]].second);
      }
    }
    
    result++;
    return true;
  } else return false;
}
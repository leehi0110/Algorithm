// ProblemNumber || ProblemName : P6593 - 상범 빌딩
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

int l, n, m;
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};

void solve();
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  while(1) {
    cin >> l >> n >> m;

    if(l == 0 && n == 0 && m == 0) break;
    else solve();
  }
}

void solve()
{
  vector<vector<vector<int>>> map(l, vector<vector<int>>(n, vector<int>(m, INF)));
  priority_queue<pair<pair<int,int>,pair<int,int>>> pq;
  int startL, startX, startY;
  int endL, endX, endY;

  for(int i=0;i<l;i++) {
    for(int j=0;j<n;j++) {
      for(int k=0;k<m;k++) {
        char state;
        cin >> state;
        
        if(state == '.') continue;
        else if(state == '#') map[i][j][k] = -1;
        else if(state == 'S'){
          startL = i;
          startX = j;
          startY = k;
        } else {
          endL = i;
          endX = j;
          endY = k;
        }
      }
    }
  }

  map[startL][startX][startY] = 0;
  pq.push({{0,startL}, {startX, startY}});

  while(!pq.empty()) {
    int cost = -pq.top().first.first;
    int f = pq.top().first.second;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    for(int i=0;i<6;i++) {
      int moveF = f + dz[i];
      int moveX = x + dx[i];
      int moveY = y + dy[i];

      if(moveF < 0 || moveX < 0 || moveY < 0 || moveF >= l || moveX >= n || moveY >= m || map[moveF][moveX][moveY] == -1 || map[moveF][moveX][moveY] <= cost + 1) continue;
      else {
        map[moveF][moveX][moveY] = cost + 1;
        pq.push({{-(cost+1), moveF}, {moveX, moveY}});
      }
    }
  }

  if(map[endL][endX][endY] == INF) cout << "Trapped!" << endl;
  else cout << "Escaped in " << map[endL][endX][endY] << " minute(s)." << endl;
}
// ProblemNumber || ProblemName : P14716 - 현수막
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
int map[251][251];
int dx[8] = {-1,1,0,0, -1, -1, 1, 1};
int dy[8] = {0,0,-1,1, 1, -1, 1, -1};

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

  int cnt = 2;
  priority_queue<pair<int,int>> pq;

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if(map[i][j] == 1) {
        pq.push({i,j});

        while(!pq.empty()) {
          int x = pq.top().first;
          int y = pq.top().second;

          pq.pop();

          for(int k=0;k<8;k++) {
            int moveX = x + dx[k];
            int moveY = y + dy[k];

            if(moveX < 0 || moveY < 0 || moveX >= n || moveY >= m || map[moveX][moveY] != 1) continue;
            else {
              map[moveX][moveY] = cnt;
              pq.push({moveX, moveY});
            }
          }
        }

        cnt++;
      }
    }
  }

  cout << cnt - 2 << endl;
}
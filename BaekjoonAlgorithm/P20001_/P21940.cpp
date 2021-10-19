// ProblemNumber || ProblemName : P21940 - 가운데서 만나기
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

int n, m;
int num;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> map(201, vector<int>(201, INF));
  vector<int> friends;
  vector<int> result;
  int minTime = INF;

  cin >> n >> m;

  for(int i=1;i<=n;i++) {
    map[i][i] = 0;
  }

  for(int i=0;i<m;i++) {
    int a, b, cost;
    cin >> a >> b >> cost;

    map[a][b] = cost;
  }
  
  for(int k=1;k<=n;k++) {
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=n;j++) {
        map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
      }
    }
  }

  // for(int i=1;i<=n;i++) {
  //   for(int j=1;j<=n;j++) {
  //     if(map[i][j] == INF) cout << "-1" << " ";
  //     else cout << map[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cin >> num;

  for(int i=0;i<num;i++) {
    int f;

    cin >> f;

    friends.push_back(f);
  }

  for(int i=1;i<=n;i++) {

    int roundMax = -1;

    for(int j=0;j<friends.size();j++) {
      int roundTime = map[friends[j]][i] + map[i][friends[j]];

      if(roundMax < roundTime) roundMax = roundTime;
    }

    if(roundMax < minTime) {
      result.clear();
      result.push_back(i);
      minTime = roundMax;
    } else if(roundMax == minTime) {
      result.push_back(i);
    }
  }

  for(int i=0;i<result.size();i++) {
    cout << result[i] << " ";
  }
  cout << endl;
}
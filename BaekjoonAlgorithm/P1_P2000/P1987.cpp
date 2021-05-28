// ProblemNumber || ProblemName : P1987 - 알파벳

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<char>> vec, vector<bool> alph, vector<vector<int>> cntVec, int nowX, int nowY, int cnt);

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int maxCnt = -1;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int nowX = 0;
  int nowY = 0;

  cin >> n >> m;

  vector<bool> alph(26, false);
  vector<vector<int>> cntVec(n, vector<int>(m, 0));
  vector<vector<char>> vec(n);

  for (int i = 0; i < n; i++)
  {
    string temp;

    cin >> temp;

    for (int j = 0; j < temp.length(); j++)
    {
      vec[i].push_back(temp[j]);
    }
  }

  DFS(vec, alph, cntVec, nowX, nowY, 1);

  cout << maxCnt << endl;
}

void DFS(vector<vector<char>> vec, vector<bool> alph, vector<vector<int>> cntVec, int nowX, int nowY, int nowCnt)
{
  if (!alph[vec[nowY][nowX] - 65] && cntVec[nowY][nowX] <= nowCnt)
  {
    if (maxCnt < nowCnt)
      maxCnt = nowCnt;
    alph[vec[nowY][nowX] - 65] = true;
    cntVec[nowY][nowX] = nowCnt;

    for (int i = 0; i < 4; i++)
    {
      int nextX = nowX + dx[i];
      int nextY = nowY + dy[i];

      if (nextX < 0 || nextY < 0 || nextX > vec[0].size() - 1 || nextY > vec.size() - 1)
        continue;
      else
      {
        DFS(vec, alph, cntVec, nextX, nextY, nowCnt + 1);
      }
    }
  }
}

// 반례
// 3 5
// ACDFE
// BGHKB
// ABCKZ

// 3 5
// ACDFE
// BGHKB
// KBCKZ
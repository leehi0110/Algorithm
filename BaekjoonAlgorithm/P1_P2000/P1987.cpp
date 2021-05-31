// ProblemNumber || ProblemName : P1987 - 알파벳
// 하면서 좀 더 깊게 생각하게 된 것들
// -> DFS에 vector를 call by value로 보낼경우 계속해서 새로운 복사본이 생기기 때문에 시간복잡도가 증가한다.
// -> 이를 해결하기 위해 배열을 사용하려 했으나 배열 자체가 주소값이기 때문에 다른 방법을 생각해야됨
// -> [nowY][nowX] 에서 [ny][nx]로 이동할 때 해당 알파벳을 사용한 것으로 체크 한뒤, 네방향에 대한 탐색이 끝나면 다시 사용하지 않은것으로 변경

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int DFS(bool alph[26], vector<vector<char>> &board, int nowX, int nowY);
// int DFS(vector<bool> alph, vector<vector<char>> &board, int nowX, int nowY);

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int nowX = 0, nowY = 0; // 말의 위치
  cin >> n >> m;

  vector<vector<char>> board(n); // 알파벳이 적혀있는 보드
  // vector<bool> alph(26, false);
  bool alph[26] = {false};

  for (int i = 0; i < n; i++)
  {
    string temp;

    cin >> temp;

    for (int j = 0; j < temp.length(); j++)
    {
      board[i].push_back(temp[j]);
    }
  } // 문자열로 입력을 받아 각 문자를 vector에 입력

  cout << DFS(alph, board, nowX, nowY) << "\n";
}

int DFS(bool alph[26], vector<vector<char>> &board, int nowX, int nowY)
// int DFS(vector<bool> alph, vector<vector<char>> &board, int nowX, int nowY)
{
  int max = 1;

  alph[board[nowY][nowX] - 65] = true;

  for (int i = 0; i < 4; i++)
  {
    int nx = nowX + dx[i];
    int ny = nowY + dy[i];

    if (nx < 0 || ny < 0 || nx >= board[0].size() || ny >= board.size() || alph[board[ny][nx] - 65])
      continue;
    else
    {
      int temp = 1 + DFS(alph, board, nx, ny);
      if (temp >= max)
        max = temp;
    }
  }

  alph[board[nowY][nowX] - 'A'] = false;

  return max;
}
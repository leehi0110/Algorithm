// ProblemNumber || ProblemName : P1987 - 알파벳

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  int nowX = 0;
  int nowY = 0;

  cin >> n >> m;

  vector<bool> alph(26, false);
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

  for (auto a : vec)
  {
    for (auto b : a)
    {
      cout << b << " ";
    }
    cout << endl;
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
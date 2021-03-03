// ProblemNumber || ProblemName : 왕실의 나이트

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N, x, y, cnt = 0;
  string site;

  vector<pair<int, int>> arr = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

  cin >> N;
  cin >> site;

  x = site[0] - 97;
  y = site[1] - '0';

  for (auto a : arr)
  {
    int nextX = a.first + x;
    int nextY = a.second + y;

    if (nextX >= 1 && nextX <= N && nextY >= 1 && nextY <= N)
    {
      cnt++;
    }
  }

  cout << cnt << endl;
}

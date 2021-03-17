// ProblemNumber || ProblemName : 2490 - 윷놀이

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  vector<char> play = {'D', 'C', 'B', 'A', 'E'};

  for (int i = 0; i < 3; i++)
  {
    int a, b, c, d;
    int cnt = 0;

    for (int j = 0; j < 4; j++)
    {
      int temp;
      cin >> temp;
      if (temp == 1)
        cnt++;
    }

    cout << play[cnt] << endl;
  }
}

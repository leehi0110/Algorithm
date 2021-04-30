// ProblemNumber || ProblemName : P1107 - 리모콘

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int target, n;
  vector<bool> broken(10, true);
  vector<int> channel(500001, INF);

  cin >> target;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int brokenNum;
    cin >> brokenNum;

    broken[brokenNum] = false;
  }

  channel[100] = 0;

  for (int i = 0; i < 500001; i++)
  {
    if (i < 100)
      channel[i] = 100 - i;
    else
      channel[i] = i - 100;
  }

  for (int i = 0; i < 500001; i++)
  {
    string s = to_string(i);

    for (int j = 0; j < s.length(); j++)
    {

      int numS = s[j] - '0';

      if (!broken[numS])
        break;

      if (j == s.length() - 1 && channel[i] > s.length())
      {
        channel[i] = s.length();
      }
    }
  }

  for (int i = 1; i < 500000; i++)
  {
    channel[i] = min(channel[i - 1] + 1, channel[i]);
    channel[i] = min(channel[i], channel[i + 1] + 1);
  }

  for (int i = 0; i < 200; i++)
  {
    cout << "Now i : " << i << " " << channel[i] << endl;
  }

  // for (int i = 499900; i < 500001; i++)
  // {
  //   cout << channel[i] << " ";
  // }
  // cout << endl;

  // cout << channel[target] << endl;
}
// ProblemNumber || ProblemName : P10953 - A + B - 6

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;

    cout << (s[0] - '0') + (s[2] - '0') << endl;
  }
}

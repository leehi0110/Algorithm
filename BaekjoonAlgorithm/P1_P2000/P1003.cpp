// ProblemNumber || ProblemName : 1003 - 피보나치 함수

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;
  vector<int> dp0(41, 0);
  vector<int> dp1(41, 0);

  cin >> testCase;

  dp0[0] = 1;
  dp0[1] = 0;

  dp1[0] = 0;
  dp1[1] = 1;

  for (int j = 2; j < 41; j++)
  {
    dp0[j] = dp0[j - 1] + dp0[j - 2];
    dp1[j] = dp1[j - 1] + dp1[j - 2];
  }

  for (int i = 0; i < testCase; i++)
  {
    int a;
    cin >> a;

    cout << dp0[a] << " " << dp1[a] << endl;
  }
}
